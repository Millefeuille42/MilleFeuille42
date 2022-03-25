#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define TP_PIPE 1
#define TP_NONE 0

typedef struct s_cmd {
	char **args;
	int argLen;
	int type;
	int curPos;
} t_cmd;

typedef struct s_list {
	t_cmd cmd;
	struct s_list *next;
	struct s_list *prev;
	struct s_list *first;
} t_list;

void fPutStr(int fd, char *s) {
	if (!s)
		return ;
	for (; *s; s++)
		write(fd, s, 1);
}

t_list *chainEnd(t_list *lst) {
	t_list *cur;

	for (cur = lst; cur->next; cur = cur->next) {}
	return cur;
}

void deleteChain(t_list *lst) {
	t_list *cur;
	t_list *next;

	for (cur = lst; cur ; cur = next) {
		next = cur->next;
		free(cur->cmd.args);
		free(cur);
	}
}

int pushChain(t_list *lst) {
	t_list *newChain = malloc(sizeof(t_list));
	if (!newChain) {
		deleteChain(lst);
		exit(-1);
	}

	newChain->cmd = (t_cmd) {
			.args = NULL, .argLen = 0, .type = 0, .curPos = 0
	};

	t_list *end = chainEnd(lst);
	end->next = newChain;
	newChain->prev = end;
	return 0;
}

int getBoardSize(int argc, char** argv, int offset) {
	int i = offset;

	for (; i < argc ; i++) {
		int isBreak = !strcmp(";", argv[i]);
		int isPipe = !strcmp("|", argv[i]);
		if (isBreak || isPipe) {
			break;
		}
	}
	return (i - offset);
}

void exec(t_cmd cmd, char **envp) {
	pid_t pid;

	if ((pid = fork()) < 0)
		exit(2);

	if (!pid) {
		int ret = execve(cmd.args[0], cmd.args, envp);
		if (ret) {
			fPutStr(2, "error: exec -> ");
			fPutStr(2, cmd.args[0]);
			fPutStr(2, "\n");
		}
		exit(ret);
	}

	int retVal = 0;
	waitpid(pid, &retVal, 0);
}

int main(int argc, char **argv, char **envp) {
	if (argc <= 1)
		goto END;

	t_cmd cmd = (t_cmd) {
		.args = NULL, .argLen = 0, .type = 0, .curPos = 0
	};

	for (int i = 1; i < argc ; i++) {
		if (!cmd.args) {
			cmd.argLen = getBoardSize(argc, argv, i);
			cmd.args = malloc((cmd.argLen + 1) * sizeof(char *));
			if (!cmd.args)
				goto MALLOC_ERROR;
			cmd.args[cmd.argLen] = NULL;
		}

		int isBreak = !strcmp(";", argv[i]);
		if (isBreak) {
			exec(cmd, envp);
			free(cmd.args);
			cmd = (t_cmd) {
				.args = NULL, .argLen = 0, .type = 0, .curPos = 0
			};
			continue ;
		}

		int isPipe = !strcmp("|", argv[i]);
		if (isPipe) {
			// Set type to PIPE
			// Create new entry in list; go next
			continue ;
		}

		cmd.args[cmd.curPos] = argv[i];
		cmd.curPos++;
	}

	exec(cmd, envp);
	free(cmd.args);

	END: return 0;
	MALLOC_ERROR: fPutStr(2, "error: fatal\n"); return -1;
}
