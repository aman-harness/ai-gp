#include <fstream>
#include <cstring>
using namespace std;
struct Student{
       string name;
       short termScore;
       short classScore;
       bool cadre;
       bool XiBu;
       bool paper;
}student[101];
        
ifstream fin("scholar.in");
ofstream fout("scholar.out");

string maxName;
short maxScore;
int total=0;

int main(){
    int n,i;
    short score,t;
    char a;
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>student[i].name>>student[i].termScore>>student[i].classScore;
        fin>>a;
        if(a=='Y') student[i].cadre=1;
        else student[i].cadre=0;
        fin>>a;
        if(a=='Y') student[i].XiBu=1;
        else student[i].XiBu=0;
        fin>>t;
        if(t>0)student[i].paper=1;
        else student[i].paper=0;
        //fout<<student[i].name<<student[i].termScore<<student[i].classScore<<student[i].cadre<<student[i].XiBu<<student[i].paper<<endl;
    }
    for(i=1;i<=n;i++){
        score=0;
        if(student[i].termScore>80 && student[i].paper!=0)
            score+=8000;
        if(student[i].termScore>85 && student[i].classScore>80)
            score+=4000;
        if(student[i].termScore>90)
            score+=2000;
        if(student[i].termScore>85 && student[i].XiBu!=0)
            score+=1000;
        if(student[i].classScore>80 && student[i].cadre!=0)
            score+=850;
        total+=score;
        if(score > maxScore){
            maxScore=score;
            maxName=student[i].name;
        }
    }
    fout<<maxName<<endl<<maxScore<<endl<<total;
    return 0;
}
