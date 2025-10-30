#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<random>
using namespace std;

#define _version "v1.0"

const string CMD_TEXT="rdgbk \b 获取版权信息和指令列表\n\
rdgbk --version \b 查看当前程序版本号\n\
rdgbk --help \b 获取帮助文档\n\
rdgbk --run \b 以默认输入输出文件路径运行程序\n\
rdgbk [输入文件路径] \b 以自定义输入文件路径和默认输出文件路径运行程序\n\
rdgbk --none [输出文件路径] \b 以默认输入文件路径和自定义输出文件路径运行程序\n\
rdgbk [输入文件路径] [输出文件路径] \b 以自定义输入文件路径和自定义输出文件路径运行程序"; 

const string HELP_TEXT=R"(#Copyright: 1724834368@qq.com
使用说明：
- random_list_GBK.txt文件由random.exe程序运行自动生成。
- random_list_GBK.txt文件内存放的内容是为random.exe程序服务的。
- random_list_GBK.txt文件的文本内容中每个待抽取项单独占一行，可包括空格等非换行字符。
- 以英文符号#开头的一行以及空行将会被忽略。
- 注意每一行的内容切勿过长，避免出现溢出错误。
- 本版本程序不会对列表文件内的项进行去重操作。
- 程序返回的抽取结果会按本文件内容的顺序展示。
- 本程序仅支持GBK字符集，其他字符集可能导致中文乱码。
- 您可以直接从Excel表格中复制几列内容后粘贴到random_list_GBK.txt文件中。
- 您可以直接在cmd命令行中使用rdgbk [读取文件路径] [输出文件路径] 运行本程序，但需要您将本程序所在目录添加环境变量Path中并为random.exe创建一个名为rdr.exe的快捷方式。这之后您还将可以使用rdgbk命令的--version和--help选项。)";

bool is_voidstr(string &s) {
	return (all_of(s.begin(),s.end(),
		[](char ch){
			return isspace(ch);
		} ));
}

bool haveBSL(string s) {
	bool ans=1;
	for(char c:s) {
		if(c=='\\') {
			return 1;
		}
	}
	return 0;
} 

int main(int argc,char *argv[]) {
	const string fpath=argv[0];
	string thisp=argv[0];
	while(thisp[thisp.size()-1]!='\\') {
		thisp.pop_back();
	}
	bool withcmd=0;
	bool cmd__run=0;
	bool no_infile=0;
	if(fpath.find("rdgbk.exe")!=string::npos && argc==1) {
		cout<<"版权：1724834368@qq.com"<<endl<<CMD_TEXT<<endl;
		withcmd=1;
	}
	if(argc>1) {
		string ar1=argv[1];
		if(argv[1][0]=='-' && argv[1][1]=='-') {	
			if(ar1=="--version") {
				cout<<"当前版本："<<_version<<endl;
				return 0;
			} else 
			if(ar1=="--help") {
				cout<<HELP_TEXT<<endl;
				return 0;
			} else
			if(ar1=="--run") {
				cmd__run=1;
			} else
			if(ar1=="--none") {
				no_infile=1;
				if(argc==2) {
					cout<<"无用的指令或选项 "<<ar1<<" ，缺少参数2！"<<endl;
					return 0; 
				} 
			}
			else {
				cout<<"错误的指令或选项 "<<ar1<<" ！"<<endl;
				return 0; 
			}
		}
	}
	if(withcmd && argc==1) return 0;
	Sleep(500); 
	if(fpath.find("random_GBK.exe")==string::npos && fpath.find("rdgbk.exe")==string::npos) {
		cout<<"-Copyright: 1724834368@qq.com\n\
您似乎擅自修改了本程序的文件名，这可能导致您为本程序配置的环境变量不可用。\n\
建议您将本程序文件名恢复为 random_GBK.exe ！\n";
		system("pause");
	}
	ofstream bout("set_rdgbk.exe_to_random_GBK.exe.bat",ios::out);
	bout<<"mklink "<<thisp<<"rdgbk.exe "<<thisp<<"random_GBK.exe\npause"<<endl;
	bout.close();
	system("cls");
	string infpath=thisp+"random_list_GBK.txt";
	string outfpath=thisp+"random_output_GBK.txt";
	if(!cmd__run) {
		if(argc>1) {
			infpath=argv[1];
			if(!haveBSL(infpath)) {
				if(!no_infile) infpath=thisp+infpath;
				else infpath=thisp+"random_list_GBK.txt";
			}
		}
		if(argc>2) {
			outfpath=argv[2];
			if(!haveBSL(outfpath)) {
				outfpath=thisp+outfpath;
			}
		}
	}
	ifstream fin(infpath,ios::in);
	if(!fin.good()) {
		cout<<"文件 "<<infpath<<" 不存在！\n\
按下 C键 将创建该文件，否则将直接退出本程序！"<<endl;
		char ch=getch(); 
		if(ch!='C' && ch!='c') {
			return 0;
		} 
		ofstream fout(infpath,ios::out);
		fout<<"#Copyright: 1724834368@qq.com\n\n\
# 使用说明：\n\
#    本文件由random.exe程序运行自动生成。\n\
#    本文件内存放的内容是为random.exe程序服务的，\n\
#    文本内容中每个待抽取项单独占一行，可包括空格等非换行字符。\n\
#    以英文符号#开头的一行以及空行将会被忽略。\n\
#    注意每一行的内容切勿过长，避免出现溢出错误。\n\
#    本版本程序不会对列表文件内的项进行去重操作。\n\
#    程序返回的抽取结果会按本文件内容的顺序展示。\n\
#    本程序仅支持GBK字符集，其他字符集可能导致中文乱码。\n\
#    您可以直接从Excel表格中复制几列内容后粘贴到本文件中。\n\
#    您可以直接在cmd命令行中使用rdgbk [读取文件路径] [输出文件路径] 运行本程序，\
但需要您将本程序所在目录添加环境变量Path中并为random.exe创建一个名为rdr.exe的快捷方式。这之后您还将可以使用rdgbk命令的--version和--help选项。\n\
#    现在尝试在本文件末尾写几行东西然后运行程序试试吧！\n\n\n\r\r\r";
		cout<<"已创建文件 "<<infpath<<" ！\n请编辑好该文件后再试！"<<endl;
		system("pause");
		fout.close();
		return 0;
	}
	vector<string> arr={};
	string s;
	while(getline(fin,s)) {
		if(is_voidstr(s)) continue; 
		if(s[0]=='#') continue;
		arr.push_back(s);
		s="";
	}
	int l=arr.size();
	//for(string a:arr) cout<<a<<endl;
	if(l==0) {
		cout<<"未发现文件 "<<infpath<<" 中有任何可用项，请重新编辑后再试！"<<endl;
		system("pause");
		return 0;
	}
	cout<<"成功读取 "<<infpath<<" 文件内容！\n\
一共检测到 "<<l<<" 个可抽取项。\n\n\
>>请输入需要抽取的项数: ";
    int n=1;
    while(1) {
    	cin>>n;
    	if(!cin.good())  {
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		system("cls");
    		cout<<"输入了非法字符，不符合要求(1-"<<l<<")！\n如果需要退出程序请输入0！\
\n\n请重新输入: ";
			continue; 
		}
    	if(n>=0 && n<=l) break;
    	system("cls");
    	cout<<"输入的数字不符合要求(1-"<<l<<")！\n如果需要退出程序请输入0！\
\n\n请重新输入: ";
	}
	if(n==0) {
		return 0;
	}
	bool suppl=0;
	if(n>=l/2) {
		suppl=1;
	}
	map<int,bool> rarr={};
	for(int i=0;i<l;i++) {
		rarr[i]=0;
	}
	int rpxlast=-1;
	if(suppl) n=l-n; //逆向思维优化 
    for (int i = 0; i < n;) {
    	//进度显示
    	int rpx=int(1.0*i/n*20);
    	if(rpx!=rpxlast) {
    		system("cls");
    		cout<<"抽取进度：[";
    		for(int j=0;j<rpx;j++) {
    			cout<<"=";
			}
			for(int j=0;j<20-rpx;j++) {
    			cout<<" ";
			}
			cout<<"]";
			rpxlast=rpx;
		}
    	string fixed_str = arr[i];
    	uint64_t fixed_hash = hash<string>{}(fixed_str);
        auto now = chrono::high_resolution_clock::now().time_since_epoch();
        uint64_t time_seed = chrono::duration_cast<chrono::nanoseconds>(now).count();
        uint64_t final_seed = static_cast<uint64_t>(i) + time_seed + fixed_hash + i;
        mt19937_64 rng(final_seed);
        uniform_int_distribution<uint64_t> dist(0, l-1);
        int rnn = dist(rng); //强制转换uint64_t了
		if(rarr[rnn]==0) {
			rarr[rnn]=1;
			i++;
		} else {
			//循环扫描按位移选择 
			int pos=rnn;
			while(1) {
				pos=(pos+1)%l;
				if(rarr[pos]==0) {
					rarr[pos]=1;
					i++;
					break;
				}
			}
		}
    }
    Sleep(500); 
	//for(int a:rarr) cout<<a<<endl;
	system("cls");
	cout<<"在"<<l<<"个可用项中随机抽取到了以下"<<(suppl? (l-n):n)<<"个项：\n\n";
    Sleep(800); 
    int cntn=0;
	for(int i=0;i<l;i++) {
		if(rarr[i] && !suppl) {
			cout<<arr[i]<<endl;
			cntn++;
		} else if(!rarr[i] && suppl) {
			cout<<arr[i]<<endl;
			cntn++;
		} else {
			//cout<<"不选中的项"<<arr[i]<<endl;
		} 
	}
	Sleep(1000);
	if(cntn!=(suppl? (l-n):n)) {
		cout<<"\n程序可能出现了莫名bug，\
抽取的项数与您输入的项数不符。请联系1724834368@qq.com反馈并等待修复版发布！\n";
	}
	cout<<"\n\n按下ESC键清屏！\n\n\n\n\n\n\n\n\n\n";
	cin.ignore();
	fflush(stdin);
	while(1) {
		char ch=getch(); 
		if(ch==27) break;
	}
	system("cls");
	ofstream fout(outfpath,ios::out);
	for(int i=0;i<l;i++) {
		if(rarr[i] && !suppl) {
			fout<<arr[i]<<endl;
		} else if(!rarr[i] && suppl) {
			fout<<arr[i]<<endl;
		}
	}
	fin.close();
	fout.close();
	cout<<"\n本次抽取内容将以GBK编码格式输出到文件 "<<outfpath<<" ！即将结束程序运行！\n\n";
	Sleep(1000); 
	system("pause");
	return 0;
}
