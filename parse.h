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
