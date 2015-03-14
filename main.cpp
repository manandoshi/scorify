#include "getsite.h"
#include "stdlib.h"

int main(){
    const char* url = "http://www.espncricinfo.com/ci/engine/match/index.html";
    const char* fname = "cric.xml";
    getSite(url,fname);
    system("notify-send \"hello\"");
    return 0;
}
