#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<random>
using namespace std;

#define _version "v1.0"

const string CMD_TEXT="rdgbk \b ��ȡ��Ȩ��Ϣ��ָ���б�\n\
rdgbk --version \b �鿴��ǰ����汾��\n\
rdgbk --help \b ��ȡ�����ĵ�\n\
rdgbk --run \b ��Ĭ����������ļ�·�����г���\n\
rdgbk [�����ļ�·��] \b ���Զ��������ļ�·����Ĭ������ļ�·�����г���\n\
rdgbk --none [����ļ�·��] \b ��Ĭ�������ļ�·�����Զ�������ļ�·�����г���\n\
rdgbk [�����ļ�·��] [����ļ�·��] \b ���Զ��������ļ�·�����Զ�������ļ�·�����г���"; 

const string HELP_TEXT=R"(#Copyright: 1724834368@qq.com
ʹ��˵����
- random_list_GBK.txt�ļ���random.exe���������Զ����ɡ�
- random_list_GBK.txt�ļ��ڴ�ŵ�������Ϊrandom.exe�������ġ�
- random_list_GBK.txt�ļ����ı�������ÿ������ȡ���ռһ�У��ɰ����ո�ȷǻ����ַ���
- ��Ӣ�ķ���#��ͷ��һ���Լ����н��ᱻ���ԡ�
- ע��ÿһ�е����������������������������
- ���汾���򲻻���б��ļ��ڵ������ȥ�ز�����
- ���򷵻صĳ�ȡ����ᰴ���ļ����ݵ�˳��չʾ��
- �������֧��GBK�ַ����������ַ������ܵ����������롣
- ������ֱ�Ӵ�Excel����и��Ƽ������ݺ�ճ����random_list_GBK.txt�ļ��С�
- ������ֱ����cmd��������ʹ��rdgbk [��ȡ�ļ�·��] [����ļ�·��] ���б����򣬵���Ҫ��������������Ŀ¼��ӻ�������Path�в�Ϊrandom.exe����һ����Ϊrdr.exe�Ŀ�ݷ�ʽ����֮������������ʹ��rdgbk�����--version��--helpѡ�)";

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
		cout<<"��Ȩ��1724834368@qq.com"<<endl<<CMD_TEXT<<endl;
		withcmd=1;
	}
	if(argc>1) {
		string ar1=argv[1];
		if(argv[1][0]=='-' && argv[1][1]=='-') {	
			if(ar1=="--version") {
				cout<<"��ǰ�汾��"<<_version<<endl;
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
					cout<<"���õ�ָ���ѡ�� "<<ar1<<" ��ȱ�ٲ���2��"<<endl;
					return 0; 
				} 
			}
			else {
				cout<<"�����ָ���ѡ�� "<<ar1<<" ��"<<endl;
				return 0; 
			}
		}
	}
	if(withcmd && argc==1) return 0;
	Sleep(500); 
	if(fpath.find("random_GBK.exe")==string::npos && fpath.find("rdgbk.exe")==string::npos) {
		cout<<"-Copyright: 1724834368@qq.com\n\
���ƺ������޸��˱�������ļ���������ܵ�����Ϊ���������õĻ������������á�\n\
���������������ļ����ָ�Ϊ random_GBK.exe ��\n";
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
		cout<<"�ļ� "<<infpath<<" �����ڣ�\n\
���� C�� ���������ļ�������ֱ���˳�������"<<endl;
		char ch=getch(); 
		if(ch!='C' && ch!='c') {
			return 0;
		} 
		ofstream fout(infpath,ios::out);
		fout<<"#Copyright: 1724834368@qq.com\n\n\
# ʹ��˵����\n\
#    ���ļ���random.exe���������Զ����ɡ�\n\
#    ���ļ��ڴ�ŵ�������Ϊrandom.exe�������ģ�\n\
#    �ı�������ÿ������ȡ���ռһ�У��ɰ����ո�ȷǻ����ַ���\n\
#    ��Ӣ�ķ���#��ͷ��һ���Լ����н��ᱻ���ԡ�\n\
#    ע��ÿһ�е����������������������������\n\
#    ���汾���򲻻���б��ļ��ڵ������ȥ�ز�����\n\
#    ���򷵻صĳ�ȡ����ᰴ���ļ����ݵ�˳��չʾ��\n\
#    �������֧��GBK�ַ����������ַ������ܵ����������롣\n\
#    ������ֱ�Ӵ�Excel����и��Ƽ������ݺ�ճ�������ļ��С�\n\
#    ������ֱ����cmd��������ʹ��rdgbk [��ȡ�ļ�·��] [����ļ�·��] ���б�����\
����Ҫ��������������Ŀ¼��ӻ�������Path�в�Ϊrandom.exe����һ����Ϊrdr.exe�Ŀ�ݷ�ʽ����֮������������ʹ��rdgbk�����--version��--helpѡ�\n\
#    ���ڳ����ڱ��ļ�ĩβд���ж���Ȼ�����г������԰ɣ�\n\n\n\r\r\r";
		cout<<"�Ѵ����ļ� "<<infpath<<" ��\n��༭�ø��ļ������ԣ�"<<endl;
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
		cout<<"δ�����ļ� "<<infpath<<" �����κο���������±༭�����ԣ�"<<endl;
		system("pause");
		return 0;
	}
	cout<<"�ɹ���ȡ "<<infpath<<" �ļ����ݣ�\n\
һ����⵽ "<<l<<" ���ɳ�ȡ�\n\n\
>>��������Ҫ��ȡ������: ";
    int n=1;
    while(1) {
    	cin>>n;
    	if(!cin.good())  {
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		system("cls");
    		cout<<"�����˷Ƿ��ַ���������Ҫ��(1-"<<l<<")��\n�����Ҫ�˳�����������0��\
\n\n����������: ";
			continue; 
		}
    	if(n>=0 && n<=l) break;
    	system("cls");
    	cout<<"��������ֲ�����Ҫ��(1-"<<l<<")��\n�����Ҫ�˳�����������0��\
\n\n����������: ";
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
	if(suppl) n=l-n; //����˼ά�Ż� 
    for (int i = 0; i < n;) {
    	//������ʾ
    	int rpx=int(1.0*i/n*20);
    	if(rpx!=rpxlast) {
    		system("cls");
    		cout<<"��ȡ���ȣ�[";
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
        int rnn = dist(rng); //ǿ��ת��uint64_t��
		if(rarr[rnn]==0) {
			rarr[rnn]=1;
			i++;
		} else {
			//ѭ��ɨ�谴λ��ѡ�� 
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
	cout<<"��"<<l<<"���������������ȡ��������"<<(suppl? (l-n):n)<<"���\n\n";
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
			//cout<<"��ѡ�е���"<<arr[i]<<endl;
		} 
	}
	Sleep(1000);
	if(cntn!=(suppl? (l-n):n)) {
		cout<<"\n������ܳ�����Ī��bug��\
��ȡ�����������������������������ϵ1724834368@qq.com�������ȴ��޸��淢����\n";
	}
	cout<<"\n\n����ESC��������\n\n\n\n\n\n\n\n\n\n";
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
	cout<<"\n���γ�ȡ���ݽ���GBK�����ʽ������ļ� "<<outfpath<<" �����������������У�\n\n";
	Sleep(1000); 
	system("pause");
	return 0;
}
