#include "shell.h"

/**
 * is_cmd - determines if a sile is an executavle command
 * @info: the info struct 
 * @path: path to the file 
 * Return: 1 if true and 0otherwise 
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path ||stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return(1);
	}
	return (0);
}

/**
 * dup_chars - duplicates cahracters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 * Return: pointer to anew buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static cahr buf[1024];
	int i = 0. k = 0;

	for (k = 0, i = start; i < stop; 1++)
		if (pathstr[1] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
 	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct 
 * @pathstr: the PATH string
 * @cmd: the cmd to find 
 * Return: full path of the cmd found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if(!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcar(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL):
}
