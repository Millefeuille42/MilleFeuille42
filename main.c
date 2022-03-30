#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define TYPE_PIPE 1

#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

typedef struct s_data {
	char **args;
	char type;
	int argCount;
} t_data;

typedef struct s_list {
		t_data data;
		char hasData;
		int pipes[2];
		struct s_list* next;
		struct s_list* previous;
} t_list;

void fPutStr(int fd, char *s) {
	for (; *s; s++)
		write(fd, s, 1);
}

void exitFatal() {
	fPutStr(2, "Error: Fatal\n");
	exit(1);
}

int argLen(int argc, char **argv) {
	int len = 1;

	for (int i = 0; i < argc; i++) {
		int isBreak = !strcmp(";", argv[i]);
		int isPipe = !strcmp("|", argv[i]);

		if (isBreak || isPipe) {
			break;
		}
		len++;
	}
	return len;
}

void clearList(t_list *cur) {
	for (t_list *next; cur;) {
		next = cur->next;
		free(cur->data.args);
		free(cur);
		cur = next;
	}
}

int newData(t_list *cur, int argc, char **argv) {
		int len = argLen(argc, argv);
	cur->data.args = malloc(sizeof(char*) * len);
	cur->data.type = 0;
	cur->data.argCount = 0;
	cur->hasData = 1;
	if (!cur->data.args) {
		return 1;
	}
	for (int i = 0; i < len; i++) {
		cur->data.args[i] = NULL;
	}
	return 0;
}

int createElement(t_list **cur) {
	*cur = malloc(sizeof(t_list));
	if (!*cur)
		return 1;
	**cur = (t_list) {.hasData = 0};
	return 0;
}

int exec(t_list *cur, char **envp) {

	if (cur->data.type == TYPE_PIPE || (cur->previous && cur->previous->data.type == TYPE_PIPE)) {
		if (pipe(cur->pipes))
			return 1;
	}

	pid_t pid = fork();

	if (pid < 0)
		return 1;
	if (!pid) {
		if (cur->data.type == TYPE_PIPE) {
			if (dup2(cur->pipes[SIDE_IN], STDOUT) < 0) {
				fPutStr(2, "Error: Fatal\n");
				exit(1);
			}
		}

		if (cur->previous && cur->previous->data.type == TYPE_PIPE) {
			if (dup2(cur->previous->pipes[SIDE_OUT], STDIN) < 0) {
				fPutStr(2, "Error: Fatal\n");
				exit(1);
			}
		}

		int ret = execve(cur->data.args[0], cur->data.args, envp);
		if (ret) {
			fPutStr(2, "error: cannot execute ");
			fPutStr(2, cur->data.args[0]);
			fPutStr(2, "\n");
		}
		exit(ret);
	} else {
		int stat;
		waitpid(pid, &stat, 0);
		if (cur->data.type == TYPE_PIPE || (cur->previous && cur->previous->data.type == TYPE_PIPE)) {
			close(cur->pipes[SIDE_IN]);
			if (!cur->next)
				close(cur->pipes[SIDE_OUT]);
		}
		if (cur->previous && cur->previous->data.type == TYPE_PIPE) {
			close(cur->previous->pipes[SIDE_OUT]);
		}
	}
	return 0;
}

void execLst(t_list *fst, char **envp) {
	for (t_list *lcur = fst; lcur; lcur = lcur->next) {
		int ret = exec(lcur, envp);
		if (ret) {
			clearList(fst);
			exitFatal();
		}
	}
}

int parse(int argc, char **argv, char **envp) {
	t_list *cur = NULL;
	t_list *fst = NULL;

	for (int i = 1; i < argc; i++) {
		int isBreak = !strcmp(";", argv[i]);
		int isPipe = !strcmp("|", argv[i]);

		if (isBreak) {
			if (!cur)
				continue;
			execLst(fst, envp);
			clearList(fst);
			cur = NULL;
			fst = NULL;
			continue;
		}
		if (isPipe) {
			if (!cur)
				continue;
			cur->data.type = TYPE_PIPE;
			if (createElement(&cur->next)) {
				clearList(fst);
				exitFatal();
				return 1;
			}
			cur->next->previous = cur;
			cur = cur->next;
			continue;
		}

		if (!cur && createElement(&cur)) {
			exitFatal();
			return 1;
		}
		if (!fst)
			fst = cur;

		if (!cur->hasData) {
			if (newData(cur, argc, argv)) {
				clearList(fst);
				exitFatal();
				return 1;
			}
		}

		cur->data.args[cur->data.argCount] = argv[i];
		cur->data.argCount++;
	}
	if (!cur)
		return 0;
	execLst(fst, envp);
	clearList(fst);
	cur = NULL;
	fst = NULL;
	return 0;
}

int main(int argc, char **argv, char **envp) {
	if (argc <= 1) {
		return 0;
	}

	parse(argc, argv, envp);
	return 0;
}
