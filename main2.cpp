#include "getsite.h"
#include "stdlib.h"
#include<cstring>
#include "parse.h"
#include "unistd.h"
const char* pteam="Scotland";

void display(game g[50])
    {
      int kk=0;
      for(kk=0;kk<50;kk++){
	if(!(strcmp(g[kk].team[0],pteam) && strcmp(g[kk].team[1],pteam))){
	  break;
	}
      }
      if(kk==50){
	return;
      }
      char* ms=g[kk].matchStatus;
      char* team1=g[kk].team[0];
      char* team2=g[kk].team[1];
      char* score1=g[kk].score[0];
      char* score2=g[kk].score[1];
        char c[500]="notify-send \"";
        int i=0,j=13;
        while(team1[i]!='\0')
        {
            c[j]=team1[i];
            i++;j++;
        }
        c[j]=' ';j++;
        c[j]='-';j++;
        c[j]=' ';j++;
        i=0;
        while(score1[i]!='\0')
        {
            c[j]=score1[i];
            i++;j++;
        }
	c[j]=' ';j++;
        c[j]='|';j++;
	c[j]='|';j++;
	c[j]=' ';j++;
        i=0;
        while(team2[i]!='\0')
        {
            c[j]=team2[i];
            i++;j++;
        }
        c[j]=' ';j++;
        c[j]='-';j++;
        c[j]=' ';j++;
        i=0;
        while(score2[i]!='\0')
        {
            c[j]=score2[i];
            i++;j++;
        }
        c[j]='"';j++;
        c[j]=' ';j++;
       	c[j]='"';j++;
	i=0;
        while(ms[i]!='\0')
        {
            c[j]=ms[i];
            i++;j++;
        }
	c[j]='"';j++;
        c[j]='\0';
        system(c);
}

int main(){
    while(true){
    const char* url = "http://www.espncricinfo.com/ci/engine/match/index.html";
    const char* fname = "cric.html";
    getSite(url,fname);
    parse();
    sleep(30);
  }
  return 0;
}
