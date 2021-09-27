//
// Created by Millefeuille on 21/06/2021.
//

char	*get_status(void)
{
	static char	status;

	return (&status);
}

char	*get_last(void)
{
	static char	last;

	return (&last);
}

unsigned char	*get_mess(void)
{
	static unsigned char	mess;

	return (&mess);
}
