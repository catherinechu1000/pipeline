#include<iostream>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<math.h>
using namespace std;
int    flushsignal = 0;
void cycle1();
void cycle2();
void cycle3();
void cycle4();
void cycle5();
void cycle6();
void cycle7();
void cycle8();
void cycle9();
void writetoreg();
void equalornot(string opcode, int lab);
void reg();
void alu();
void mem();
void write();
void rtype();
void hazarddetectionunit(int rs, int rt);
void itype(string op);
bool r = false;
bool it = false;
bool destination1write = false;
bool destination2write = false;
bool memread = false;
string functionn = "";
string ifetch(int a);
int fowardingunit2 = 0;
int fowardingunit = 0;
string fowardingunit3 = "";

int pc = 4;
int ReadData1 = 0;
int ReadData2 =	0;
int sign_ext =0;
int Rs = 0;
int Rt = 0;
int Rd = 0;
int destination1 = 0;
int destination2 = 0;
string signals1 = "000000000";
int ReadData = 0;
int WriteData = 0;
int ALUout1	= 0;
int ALUout2	= 0;
string foward = "00";//10->2、01->1
string signals2 = "00000";
string signals3 = "00";
string instruction = "00000000000000000000000000000000";
int immediate = 0;
int $0 = 0;
int $1 = 9;
int $2 = 8;
int $3 = 7;
int $4 = 1;
int $5 = 2;
int $6 = 3;
int $7 = 4;
int $8 = 5;
int $9 = 6;
int x00 = 5;
int x04 = 9;
int x08 = 4;
int x0C = 8;
int x10 = 7;
int incount = 1;
int label = 0;

void flushornot();
int main(){
    cycle1();

}

void cycle1(){
    fstream fp;
    fp.open("loadResult.txt",ios::out);
    fp<<"CC1:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;
    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData2<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount ++;

    cycle2();


}
void cycle2(){
    pc = pc+4;
    reg();
    fstream fp;
    fp.open("loadResult.txt",ios::out|ios::app);
    fp<<"CC2:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;

    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount ++ ;
    flushornot();
    cycle3();


}
void cycle3(){
    pc = pc+4;
    alu();
    reg();
    fstream fp;
    fp.open("loadResult.txt",ios::out|ios::app);
    fp<<"CC3:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;
    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount++;
    flushornot();
    cycle4();
}
void cycle4(){
    pc = pc+4;
    mem();
    alu();
    reg();
    fstream fp;
    fp.open("loadResult.txt",ios::out|ios::app);
    fp<<"CC4:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;
    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount++;
    flushornot();
    cycle5();

}
void cycle5(){
    pc = pc+4;
    writetoreg();
    mem();
    alu();
    reg();
    fstream fp;
    fp.open("loadResult.txt",ios::out|ios::app);
    fp<<"CC5:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;
    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount++;
    flushornot();
    cycle6();

}
void cycle6(){
    pc = pc+4;
    writetoreg();
    mem();
    alu();
    reg();
    fstream fp;
    fp.open("loadResult.txt",ios::out|ios::app);
    fp<<"CC6:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;
    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount++;
    flushornot();
    cycle7();


}

void cycle7(){
    pc = pc+4;
    writetoreg();
    mem();
    alu();
    reg();
    fstream fp;
    fp.open("loadResult.txt",ios::out|ios::app);
    fp<<"CC7:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;
    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount++;
    flushornot();
    cycle8();



}
void cycle8(){
    pc = pc+4;
    writetoreg();
    mem();
    alu();
    reg();
    fstream fp;
    fp.open("loadResult.txt",ios::out|ios::app);
    fp<<"CC8:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;
    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount++;
    flushornot();
    cycle9();
}
void cycle9(){
    pc = pc+4;
    writetoreg();
    mem();
    alu();
    reg();
    fstream fp;
    fp.open("loadResult.txt",ios::out|ios::app);
    fp<<"CC9:"<<endl;
    fp<<"Registers:"<<endl;
    fp<<"$0:"<<$0<<endl;
    fp<<"$1:"<<$1<<endl;
    fp<<"$2:"<<$2<<endl;
    fp<<"$3:"<<$3<<endl;
    fp<<"$4:"<<$4<<endl;
    fp<<"$5:"<<$5<<endl;
    fp<<"$6:"<<$6<<endl;
    fp<<"$7:"<<$7<<endl;
    fp<<"$8:"<<$8<<endl;
    fp<<"$9:"<<$9<<endl;
    fp<<"Data memory:"<<endl;
    fp<<"0x00:"<<x00<<endl;
    fp<<"0x04:"<<x04<<endl;
    fp<<"0x08:"<<x08<<endl;
    fp<<"0x0C:"<<x0C<<endl;
    fp<<"0x10:"<<x10<<endl;
    fp<<"IF/ID :"<<endl;
    fp<<"PC"<<" "<<pc<<endl;
    fp<<"Instruction:"<<ifetch(incount)<<endl;
    fp<<"ID/EX :"<<endl;
    fp<<"ReadData1:"<<ReadData1<<endl;
    fp<<"ReadData2:"<<ReadData2<<endl;
    fp<<"sign_ext:"<<sign_ext<<endl;
    fp<<"Rs:"<<Rs<<endl;
    fp<<"Rt:"<<Rt<<endl;
    fp<<"Rd:"<<Rd<<endl;
    fp<<"Control signals"<<signals1<<endl;

    fp<<"EX/MEM :"<<endl;
    fp<<"ALUout:"<<ALUout1<<endl;
    fp<<"WriteData"<<WriteData<<endl;
    fp<<"Rt/Rd"<<destination1<<endl;
    fp<<"signals2"<<signals2<<endl;

    fp<<"MEM/WB :"<<endl;
    fp<<"ReadData"<<ReadData<<endl;
    fp<<"ALUout"<<ALUout2<<endl;
    fp<<"Rt/Rd"<<destination2<<endl;
    fp<<"Control signals"<<signals3<<endl;
    fp.close();
    incount++;


}

string ifetch(int a){
    ifstream fin("Lwhazard.txt");
    cout<<a<<endl;
    for(int i=1;i<=a;i++){
        if(fin.eof()){
            instruction = "00000000000000000000000000000000";
        }
        else
            fin>>instruction;
    }


    fin.close();
    return instruction;
}
void reg(){
    string op = "";
    signals1 = "000000000";
    for(int i=0;i<6;i++){
        op = op + instruction[i];
    }
    if(op == "000000"){
        rtype();
    }

    else{

        itype(op);
    }

}
void rtype(){

    string a;
    string s;   //rs
    string t;   //rt
    string d;   //rd
    int ss = 0;     //rs
    int tt = 0;     //rt
    int dd = 0;     //rd
    Rs = 0;
    Rt = 0;
    Rd = 0;
    for(int i=26;i<=31;i++){
        a = a+instruction[i];
    }
    if(a == "000000"){
        functionn = "";
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;

        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;

        for(int i=16;i<=20;i++){
            int b = instruction[i]-'0';
            dd = dd + b*pow(2,(20-i));
        }
        Rd = dd;

        for(int i=26;i<=31;i++){
            functionn = functionn + instruction[i];
        }
        signals1 = "000000000";


    }

    if(a == "100010"){//sub
        functionn = "";
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;

        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;

        for(int i=16;i<=20;i++){
            int b = instruction[i]-'0';
            dd = dd + b*pow(2,(20-i));
        }
        Rd = dd;

        for(int i=26;i<=31;i++){
            functionn = functionn + instruction[i];
        }
        signals1 = "110000010";



    }
    if(a == "100000"){//add
        functionn = "";
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;

        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;

        for(int i=16;i<=20;i++){
            int b = instruction[i]-'0';
            dd = dd + b*pow(2,(20-i));
        }
        Rd = dd;

        for(int i=26;i<=31;i++){
            functionn = functionn + instruction[i];
        }
        signals1 = "110000010";


    }
    if(a == "100100"){//and
        functionn = "";
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;
        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;
        for(int i=16;i<=20;i++){
            int b = instruction[i]-'0';
            dd = dd + b*pow(2,(20-i));
        }
        Rd = dd;

        for(int i=26;i<=31;i++){
            functionn = functionn + instruction[i];
        }
        signals1 = "110000010";


    }
    if(a == "100111"){//nor
        functionn = "";
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;
        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;
        for(int i=16;i<=20;i++){
            int b = instruction[i]-'0';
            dd = dd + b*pow(2,(20-i));
        }
        Rd = dd;

        for(int i=26;i<=31;i++){
            functionn = functionn + instruction[i];
        }
        signals1 = "110000010";


    }
    if(a == "100101"){//or
        functionn = "";
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;

        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;

        for(int i=16;i<=20;i++){
            int b = instruction[i]-'0';
            dd = dd + b*pow(2,(20-i));
        }
        Rd = dd;

        for(int i=26;i<=31;i++){
            functionn = functionn + instruction[i];
        }
        signals1 = "110000010";

    }
    if(a == "101010"){//slt
        functionn = "";
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;

        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;

        for(int i=16;i<=20;i++){
            int b = instruction[i]-'0';
            dd = dd + b*pow(2,(20-i));
        }
        Rd = dd;


        for(int i=26;i<=31;i++){
            functionn = functionn + instruction[i];
        }
        signals1 = "110000010";


    }
    sign_ext = 0;
    if(Rs == 0){
        ReadData1 = $0;
    }
    if(Rs == 1){
        ReadData1 = $1;
    }
    if(Rs == 2){
        ReadData1 = $2;
    }
    if(Rs == 3){
        ReadData1 = $3;
    }
    if(Rs == 4){
        ReadData1 = $4;
    }
    if(Rs == 5){
        ReadData1 = $5;
    }
    if(Rs == 6){
        ReadData1 = $6;
    }
    if(Rs == 7){
        ReadData1 = $7;
    }
    if(Rs == 8){
        ReadData1 = $8;
    }
    if(Rs == 9){
        ReadData1 = $9;
    }
    if(Rt == 0){
        ReadData2 = 0;
    }
    if(Rt == 1){
        ReadData2 = $1;
    }
    if(Rt == 2){
        ReadData2 = $2;
    }
    if(Rt == 3){
        ReadData2 = $3;
    }
    if(Rt == 4){
        ReadData2 = $4;
    }
    if(Rt == 5){
        ReadData2 = $5;
    }
    if(Rt == 6){
        ReadData2 = $6;
    }
    if(Rt == 7){
        ReadData2 = $7;
    }
    if(Rt == 8){
        ReadData2 = $8;
    }
    if(Rt == 9){
        ReadData2 = $9;
    }
    r = false;
    hazarddetectionunit(Rs,Rt);

}
void itype(string op){
    flushsignal = 0;
    int ss = 0;
    int tt = 0;
    int dd = 0;
    immediate = 0;
    label = 0;
    Rs = 0;
    Rt = 0;
    Rd = 0;
    if(op == "000100"){//beq
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;

        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;

        for(int i=16;i<=31;i++){
            int b = instruction[i]-'0';
            label = label + b*pow(2,(31-i));
        }

        signals1 = "001010000";
    }

    if(op == "000101"){//bne
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;

        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;

        for(int i=16;i<=31;i++){
            int b = instruction[i]-'0';
            label = label + b*pow(2,(31-i));
        }

        signals1 = "001010000";

    }
    if(op == "001000"){ // addi
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;

        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;

        for(int i=16;i<=31;i++){
            int b = instruction[i]-'0';
            immediate = immediate + b*pow(2,(31-i));
        }

        signals1 = "000100010";

    }


    if(op == "100011"){ // lw

        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;


        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;


        for(int i=16;i<=31;i++){
            int b = instruction[i]-'0';
            immediate = immediate + b*pow(2,(31-i));
        }

        sign_ext = immediate;
        signals1 = "000101011";


    }
    if(op == "101011"){//sw

        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;


        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;


        for(int i=16;i<=31;i++){
            int b = instruction[i]-'0';
            immediate = immediate + b*pow(2,(31-i));
        }

        signals1 = "000100100";
    }
    if(op == "001100"){
        for(int i=6;i<=10;i++){     //拿rs
            int b = instruction[i]-'0';
            ss = ss + b*pow(2,(10-i));
        }
        Rs = ss;


        for(int i=11;i<=15;i++){
            int b = instruction[i]-'0';
            tt = tt + b*pow(2,(15-i));
        }
        Rt = tt;


        for(int i=16;i<=31;i++){
            int b = instruction[i]-'0';
            immediate = immediate + b*pow(2,(31-i));
        }

        signals1 = "011100010";
    }


    if(Rs == 0){
        ReadData1 = $0;
    }
    if(Rs == 1){
        ReadData1 = $1;
    }
    if(Rs == 2){
        ReadData1 = $2;
    }
    if(Rs == 3){
        ReadData1 = $3;
    }
    if(Rs == 4){
        ReadData1 = $4;
    }
    if(Rs == 5){
        ReadData1 = $5;
    }
    if(Rs == 6){
        ReadData1 = $6;
    }
    if(Rs == 7){
        ReadData1 = $7;
    }
    if(Rs == 8){
        ReadData1 = $8;
    }
    if(Rs == 9){
        ReadData1 = $9;
    }
    if(Rt == 0){
        ReadData2 = 0;
    }
    if(Rt == 1){
        ReadData2 = $1;
    }
    if(Rt == 2){
        ReadData2 = $2;
    }
    if(Rt == 3){
        ReadData2 = $3;
    }
    if(Rt == 4){
        ReadData2 = $4;
    }
    if(Rt == 5){
        ReadData2 = $5;
    }
    if(Rt == 6){
        ReadData2 = $6;
    }
    if(Rt == 7){
        ReadData2 = $7;
    }
    if(Rt == 8){
        ReadData2 = $8;
    }
    if(Rt == 9){
        ReadData2 = $9;
    }
    it = false;
    if(op == "000100" || op == "000101"){
        equalornot(op,label);
    }

}
void alu(){     //現在在灌的就是上一個

    if(signals3 == "00010" && destination2!= 0 && destination2 == Rs){//前一個是rtype
        cout<<"in1"<<endl;
        foward = "10";
        ReadData1 = ALUout1;
    }
    if(signals3 == "00010" && destination2!= 0 && destination2 == Rt){//前一個是rtype
        cout<<"in2"<<endl;
        foward = "10";
        ReadData2 = ALUout1;
    }
    if(fowardingunit3 == "10" && fowardingunit!= 0 && fowardingunit!=destination2 && fowardingunit == Rs){//前兩個是rtype
        cout<<"in3"<<endl;
        foward = "01";
        ReadData1 = fowardingunit2;
    }
    if(fowardingunit3 == "10" && fowardingunit!= 0 && fowardingunit!=destination2 && fowardingunit == Rt){//前兩個是rtype
        cout<<"in4"<<endl;
        foward = "01";
        ReadData2 = fowardingunit2;
    }
    if(fowardingunit3 == "11" && fowardingunit!=0 && fowardingunit!=destination2 &&fowardingunit == Rs){//前兩個是lw
        cout<<"in5"<<endl;
        ReadData1 = fowardingunit2;
    }
    if(fowardingunit3 == "11" && fowardingunit!=0 && fowardingunit!=destination2 && fowardingunit == Rt){//前兩個是lw
        cout<<"in6"<<endl;
        ReadData2 = fowardingunit2;
    }

    /*if(signals1 == "110000010" && destination1!= 0 && destination1 == Rs && signals2 != "01011"){
        cout<<"in1"<<destination1<<endl;
        foward = "10";
        ReadData1 = ALUout1;
    }
    else if(destination2write == true && fowardingunit!= 0 && fowardingunit == Rs ){
        cout<<"in2"<<endl;
        foward = "01";
        ReadData1 = fowardingunit2;
    }
    if(destination1write == true && destination1!= 0 && destination1 == Rt && signals2 != "01011"){
        cout<<"in3"<<endl;
        foward = "10";
        ReadData2 = ALUout1;
    }
    else if(destination2write == true && fowardingunit!= 0  && fowardingunit == Rt){
        cout<<"in4"<<endl;
        foward = "01";
        ReadData2 = fowardingunit2;
    }*/

    string aluop;
    string aluctr;
    ALUout1 = 0;
    for(int i=1;i<=2;i++){
        aluop = aluop +signals1[i];
    }
    if(aluop == "11"){
        aluctr = "000";
    }
    if(aluop == "00"){
        aluctr = "010";
    }
    if(aluop == "01"){
        aluctr = "110";
    }
    if(aluop == "10"){
        if(functionn == "100000"){
            aluctr = "010";
        }
        if(functionn == "100010"){
            aluctr = "110";
        }
        if(functionn == "100100"){
            aluctr = "000";
        }
        if(functionn == "100101"){
            aluctr = "001";
        }
        if(functionn == "101010"){//slt
            aluctr = "111";
        }

    }

    //開始exe

    if(aluctr == "010"){//add

        if(signals1 == "110000010"){ //rtype
            cout<<"add"<<endl;
            cout<<fowardingunit3<<" "<<fowardingunit2<<" "<<destination2<<endl;
            cout<<Rs<<"             "<<Rt<<endl;
            cout<<signals2<<"       "<<signals3<<endl;
            cout<<ReadData1<<"         "<<ReadData2<<endl;
            cout<<$6<<"            "<<$5<<endl;
            ALUout1 = ReadData1 + ReadData2;
            destination1 = Rd;
        }
        else if(signals1 == "000100010"){//addi
            ALUout1 = ReadData1 + immediate;
            destination1 = Rt;

        }
        else if(signals1 == "000100100"){//sw


            ALUout1 = ReadData1 + immediate;
            destination1 = ALUout1;
            WriteData = ReadData2;
        }
        else{
            ALUout1 = ReadData1 + immediate; //lw
            destination1 = Rt;


        }
    }
    if(aluctr == "110"){//sub
        if(signals1 == "110000010" || signals1 == "001010000"){
            ALUout1 = ReadData1 - ReadData2;
            destination1 = Rd;
        }
    }
    if(aluctr == "001"){//or，把data1 data2換成2進位
        string data1 = "";
        string data2 = "";
        string temp = "";
        char s[5];
        char d[5];
        stringstream ss;
        stringstream mm;
        int da1 = ReadData1;
        int da2 = ReadData2;
        for(int i=0;i<5;i++){
            int ans = da1%2;
            da1 = da1/2;
            sprintf(s,"%d",ans);
            data1 = data1 +s;
        }


        for(int i=4;i>=0;i--){
            temp = temp + data1[i];
        }

        for(int i=0;i<5;i++){
            data1[i] = temp[i];
        }
        for(int i=0;i<5;i++){
            int ans = da2%2;
            da2 = da2/2;
            sprintf(d,"%d",ans);
            data2 = data2 +d;
        }

        temp = "";
        for(int i=4;i>=0;i--){
            temp = temp + data2[i];
        }
        for(int i=0;i<5;i++){
            data2[i] = temp[i];
        }
        for(int i=0;i<5;i++){
            if(data1[i] == '1' || data2[i] == '1'){
                temp[i] = '1';
            }
            else
                temp[i] = '0';
        }
        //cout<<temp<<endl;
        for(int i=0;i<5;i++){
            ALUout1 = ALUout1 + (temp[i]-'0')*pow(2,(4-i));
        }
        destination1 = Rd;


    }
    if(aluctr == "111"){//set on less than
        if(ReadData1<ReadData2){
            ALUout1 = 1;
            destination1 = Rd;
        }
    }
    if(aluctr == "000"){
        if(signals1 == "110000010"){//and
        string data1 = "";
        string data2 = "";
        string temp = "";
        char s[5];
        char d[5];
        stringstream ss;
        stringstream mm;
        int da1 = ReadData1;
        int da2 = ReadData2;
        for(int i=0;i<5;i++){
            int ans = da1%2;
            da1 = da1/2;
            sprintf(s,"%d",ans);
            data1 = data1 +s;
        }


        for(int i=4;i>=0;i--){
            temp = temp + data1[i];
        }

        for(int i=0;i<5;i++){
            data1[i] = temp[i];
        }

        for(int i=0;i<5;i++){
            int ans = da2%2;
            da2 = da2/2;
            sprintf(d,"%d",ans);
            data2 = data2 +d;
        }

        temp = "";
        for(int i=4;i>=0;i--){
            temp = temp + data2[i];
        }
        for(int i=0;i<5;i++){
            data2[i] = temp[i];
        }

        for(int i=0;i<5;i++){
            if(data1[i] == '1' && data2[i] == '1'){
                temp[i] = '1';
            }
            else
                temp[i] = '0';
        }
        //cout<<temp<<endl;
        for(int i=0;i<5;i++){
            ALUout1 = ALUout1 + (temp[i]-'0')*pow(2,(4-i));
        }
        destination1 = Rd;

    }
    if(signals1 == "011100010"){//andi
        cout<<"andi"<<immediate<<" "<<ReadData1<<endl;
        string data1 = "";
        string imme = "";
        string temp = "";
        char s[5];
        char m[5];
        int da1 = ReadData1;
        int imm = immediate;
        for(int i=0;i<5;i++){
            int ans = da1%2;
            da1 = da1/2;
            sprintf(s,"%d",ans);
            data1 = data1 +s;
        }


        for(int i=4;i>=0;i--){
            temp = temp + data1[i];
        }

        for(int i=0;i<5;i++){
            data1[i] = temp[i];
        }
        for(int i=0;i<5;i++){
            int ans = imm%2;
            imm = imm/2;
            sprintf(m,"%d",ans);
            imme = imme + m;
        }
        temp = "";
       for(int i=4;i>=0;i--){
            temp = temp + imme[i];
        }

        for(int i=0;i<5;i++){
            imme[i] = temp[i];
        }
        cout<<"data"<<data1<<"imme"<<imme<<endl;
        for(int i=0;i<5;i++){
            if(data1[i] == '1' && imme[i] == '1'){
                temp[i] = '1';
            }
            else
                temp[i] = '0';
        }
        //cout<<temp<<endl;
        for(int i=0;i<5;i++){
            ALUout1 = ALUout1 + (temp[i]-'0')*pow(2,(4-i));
        }


        destination1 = Rt;

    }
}
    if(signals1 == "000000000"){
        signals2 = "00000";
    }
    if(signals1 == "110000010"){ // rtype
        signals2 = "00010";

    }
    if(signals1 == "011100010"){
        signals2 = "00010";
    }
    if(signals1 == "000101011"){ //lw
        signals2 = "01011";

    }
    if(signals1 == "001010000"){
        signals2 = "10000";
    }

    if(signals1 == "000100010"){//addi
        signals2 = "00010";
    }
    if(signals1 == "000100100"){//sw
        signals2 = "00100";
    }
    if(signals1 == "110000010"){//rtype
        destination1write = true;

    }
    else if(signals1 == "000101011"){//sw
        destination1write = true;

    }
    else{
        destination1write = false;
    }



}
void mem(){
    destination2 = destination1;
    ALUout2 = ALUout1;
    if(signals2 == "00000"){
        signals3 = "00";
    }
    if(signals2 == "00100"){//sw
        if(destination1 == 0){
            x00 = WriteData;
        }
        if(destination1 == 4){
            x04 = WriteData;
        }
        if(destination1 == 8){
            x08 = WriteData;
        }
        if(destination1 == 12){
            x0C = WriteData;
        }
        if(destination1 == 16){
            x10 = WriteData ;
        }
        signals3 = "00";
    }
    if(signals2 == "01011"){//lw
        if(ALUout2 == 0 ){
            ReadData = x00;
        }
        if(ALUout2 == 4){
            ReadData = x04;
        }
        if(ALUout2 == 8){
            ReadData = x08;
        }
        if(ALUout2 == 12){
            ReadData = x0C;
        }
        if(ALUout2 == 16){
            ReadData = x10;
        }
        signals3 = "11";

    }
    if(signals2 == "00010"){ //rtype
        signals3 = "10";
    }
    if(signals2 == "01011" || signals2 == "00010"){
        destination2write = true;
    }
    else{
        destination2write = false;
    }


}
void writetoreg(){//rtype，lw才會用到 sw的signal3 == 01 or 00
     fowardingunit = destination2;
     fowardingunit3 = signals3;
     if(signals3 == "10"){//rtype
        if(destination2 == 0){
            $0 = 0;
        }
        if(destination2 == 1){
            $1 = ALUout2;
        }
        if(destination2 == 2){
            $2 = ALUout2;
        }
        if(destination2 == 3){
            $3 = ALUout2;
        }
        if(destination2 == 4){
            $4 = ALUout2;
        }
        if(destination2 == 5){
            $5 = ALUout2;
        }
        if(destination2 == 6){
            $6 = ALUout2;
        }
        if(destination2 == 7){
            $7 = ALUout2;
        }
        if(destination2 == 8){
            $8 = ALUout2;
        }
        if(destination2 == 9){
            $9 = ALUout2;
        }
        fowardingunit2 = ALUout2;
     }
     if(signals3 == "11"){//lw
        if(destination2 == 0){
            $0 = 0;
        }
        if(destination2 == 1){
            $1 = ReadData;
        }
        if(destination2 == 2){
            $2 = ReadData;
        }
        if(destination2 == 3){
            $3 = ReadData;
        }
        if(destination2 == 4){
            $4 = ReadData;
        }
        if(destination2 == 5){
            $5 = ReadData;
        }
        if(destination2 == 6){
            $6 = ReadData;
        }
        if(destination2 == 7){
            $7 = ReadData;
        }
        if(destination2 == 8){
            $8 = ReadData;
        }
        if(destination2 == 9){
            $9 = ReadData;
        }
        fowardingunit2 = ReadData;
     }
}
     void hazarddetectionunit(int rs, int rt){

        if(signals2 == "01011" && rs == destination1){
            pc = pc-4;
            signals1 = "000000000";
            incount--;

        }
        if(signals2 == "01011" && rt == destination1){
            pc = pc-4;
            signals1 = "000000000";
            incount--;
        }

     }
     void equalornot(string opcode, int lab){
        if(opcode == "000100"){//beq
            if(ReadData1 == ReadData2){
                flushsignal = 1;
            }
            else
                flushsignal = 0;
        }
        if(opcode == "000101"){//bne
            if(ReadData1 != ReadData2){
                flushsignal = 1;
            }
            else
                flushsignal = 0;
        }


     }
     void flushornot(){//決定下一個要fetch的
            if(flushsignal == 1){
                instruction = "00000000000000000000000000000000";
                incount = incount+label-1;
                pc = pc + 4*(label-1);
            }
            flushsignal = 0;

     }



