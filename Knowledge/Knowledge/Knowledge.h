#ifndef __KNOWLEDGE_H__
#define __KNOWLEDGE_H__

extern int UseCamera(int argc, char *argv[]);
extern int PlayVideo(int argc, char *argv[]);
extern int ShowImage(int argc, char *argv[]);
extern int ImageErode(int argc, char *argv[]);
extern int BlurImage(int argc, char *argv[]);


typedef int (*cmd_fun)(int argc, char*argv[]);


#endif