#include "Knowledge.h"
#include <stdio.h>
#include <string.h>
#define KL_CMD_ARG_LEN (100)
#define KL_CM_ARG_NUM  (10)

typedef struct
{
	char *name;
	cmd_fun cmdfun;
}KL_CMD_ST;


int help(int argc, char *argv[]);

KL_CMD_ST g_cmds[] =
{
	{ "usecamera", UseCamera },
	{ "playvideo", PlayVideo },
	{ "showimage", ShowImage },
	{ "erodeimage", ImageErode },
	{ "blurimage", BlurImage },
	{ "help",help }
};
int g_cmd_size = sizeof(g_cmds) / sizeof(g_cmds[0]);

int help(int argc, char *argv[])
{
	int cmd_num = g_cmd_size;
	int i = 0;
	for (i = 0; i < cmd_num; i++)
	{
		if (NULL != g_cmds[i].name)
		{
			printf("cmd:%s,\n", g_cmds[i].name);
		}		
	}
	return 0;
}
int KL_GetLine(char s[], int lenMax)
{
	int c, i;
	i = 0;
	while ((c = getchar()) != EOF && c != '\n' &&i < lenMax - 1)
	{
		s[i++] = c;
	}		
	s[i] = '\0';

	return i;
}

/*空格隔开参数*/
void KL_ParseInput(char *input, int input_len, int *argc, char *argv[KL_CM_ARG_NUM])
{
	int i = 0;
	int j = 0;
	int arg_num = 0;
	int arg_len = 0;
	int arg_flag = 0;
	for (i = 0; i < input_len; i++)
	{
		if (' ' == input[i] || '\n' == input[i] )
		{
			if (0 == arg_flag)
			{	
				arg_flag = 1;
				argv[arg_num][arg_len] = '\0';
				arg_len = 0;
				arg_num++;
			}
			
		}
		else
		{
			if (1 == arg_flag)
			{
				arg_flag = 0;
			}
			argv[arg_num][arg_len++] = input[i];
		}
	}
	*argc = arg_num+1;
}
int main()
{
	char input[1024] = { 0 };
	int len = 0;
	char input_array[KL_CM_ARG_NUM][KL_CMD_ARG_LEN] = { 0 };
	char *input_args[KL_CM_ARG_NUM] = { NULL };
	int input_argc = 0;
	int i = 0;


	for (i = 0; i < KL_CM_ARG_NUM; i++)
	{
		input_args[i] = input_array[i];
	}

	while (1)
	{
		printf("KL>");
		memset(input, 0, 1024);
		memset(input_array, 0, KL_CM_ARG_NUM*KL_CMD_ARG_LEN);
		len = KL_GetLine(input, 1024);
		if (0 == len)
		{
			printf("\n");
			continue;
		}

		KL_ParseInput(input, len,&input_argc,input_args);	

		for (i = 0; i < g_cmd_size; i++)
		{
			if (0 == strncmp(input_args[0], g_cmds[i].name, strlen(g_cmds[i].name)))
			{
				printf("run cmd:%s\n", g_cmds[i].name);
				g_cmds[i].cmdfun(input_argc, input_args);
			}
			
		}
	}
	return 0;
}