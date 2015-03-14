#include "getsite.h"
#include "stdlib.h"
#include<cstring>
struct game{
  char team[2][100];
  char score[2][100];
};
void display(game*);
void parseFinal(char matchData[25][500],int ii, game g[50]){
  
  char team[2][100], score[2][100];
  const char* key="   <div class=\"innings-info-1\">\n";
  for(int i2 = 0; i2 < 25; i2++)
  {
      if(!strcmp(matchData[i2],key)){
	for(int j1=0; j1<2; j1++){
	  int lNum = i2 + 1 + j1*3;
	  int index = 0,teamIndex=0;
	  while(matchData[lNum][index] != '<')
	    {
	      team[j1][index] = matchData[lNum][index];
	      index++;
	      teamIndex++;
	    }
      
	  while(matchData[lNum][index] != '>')
	    index++;

	  int scoreIndex = 0;
	  index++;
      
	  while(matchData[lNum][index] != '<')
	    {
	      score[j1][scoreIndex] = matchData[lNum][index];
	      index++;
	      scoreIndex++;
	    }

	  int j = teamIndex-1;
      
	  while(team[j1][j] == ' '){
	    j--;
	  }
	  team[j1][j+1] = '\0';
           
	  j = scoreIndex;
      
	  while(score[j1][j] != ')' && j >= 0)
	    j--;
	  score[j1][j+1] = '\0';
	}
	break;
      }
  }
  strcpy(g[ii].team[0],team[0]);
  strcpy(g[ii].team[1],team[1]);
  strcpy(g[ii].score[0],score[0]);
  strcpy(g[ii].score[1],score[1]);
}

void parse(){
        const char* key= " <section class=\"matches-day-block\">\n";
        const char* key2="  <section class=\"default-match-block\">\n";
	game g[50];
	int ii=0;
        char linestr[80];
        char out[25][500];
        FILE* fpin;
        fpin=fopen("cric.html","r");
        fgets(linestr,499,fpin);
        while(!feof(fpin)){
                if(strcmp(key,linestr)==0){
                        while(true){                    
                                for(int i=0;i<25;i++){
                                        fgets(out[i],499,fpin);
                                }
                                if(!strcmp(out[0],key2)){
				  parseFinal(out,ii,g);
				  ii++;
                                }
                                else{
                                        break;
                                }
                        }
                }
                fgets(linestr,499,fpin);
        }
	display(g);
}


void display(game g[50])
    {
      int kk=0;
      char* team1=g[kk].team[0];
      char* team2=g[kk].team[1];
      char* score1=g[kk].score[0];
      char* score2=g[kk].score[1];
        char c[500]="notify-send \"\"";
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
        c[j]='\\';j++;
        c[j]='"';j++;
        c[j]='"';j++;
        c[j]='\0';
        system(c);
}

int main(){
  const char* url = "http://www.espncricinfo.com/ci/engine/match/index.html";
  const char* fname = "cric.html";
  getSite(url,fname);
  parse();
  return 0;
}
