#include"holder.h"
#include<map>
#include"fileread.h"
#include"interface.h"
#include<conio.h>
#include<vector>
#include<algorithm>
extern Interface interface;
void Holder::show_date() {
	system("cls");
	cout << "ID\t" << "year\t" << "day\t" << endl;
	for (multimap<int, int>::iterator i = hold_date.begin(); i != hold_date.end(); i++) {
		int year, day;
		
		year = (i->second) / 360;
		day = (i->second) - year*360;
		cout << i->first << "\t" << year << "\t" << day << endl;
	}
	
}
void Holder::show_id() {
	system("cls");
	system("mode con cols=67 lines=34");
	system("color 06");
	cout << "ID\t" << "year\t" << "day\t" << endl;
	for(multimap<int,int>::iterator i = hold_id.begin();i != hold_id.end();i++){
		int year, day;
		
		year = (i->second)/360;
		day = (i->second)  - year*360;
		cout<<i->first<<"\t"<<year<<"\t"<<day<<endl;
	}
	
}
typedef pair<int, int> PAIR;//�Ƚ�map  value�ķ���
ostream& operator<<(ostream& out, const PAIR& p) {
	int year, day;

	year = (p.second) / 360;
	day = (p.second) - year * 360;
	return out << p.first << "\t" <</* p.second;*/year<<"\t"<< day ;
}


bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second < rhs.second;
}

struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second < rhs.second;
	}
};
/*map<int, int>*/void Holder::sort_date() {//����������(value)

	multimap<int, int> sort_date = hold_id;
	multimap<int, int> time;
	//��map�е�Ԫ��ת�浽vector��
	vector<pair<int, int>>  vec(sort_date.begin(), sort_date.end());
	sort(vec.begin(), vec.end(), CmpByValue());
	/*for (int i = 0; i != vec.size(); ++i) {
		time.insert(vec[i]);
	}
	return time;*/
	cout << "ID\t" << "year\t" << "day\t" << endl;
	for (int i = 0; i != vec.size(); ++i) {
		cout << vec[i] << endl;
	}
}
void Holder::show_key(int key) {
	cout << "ID\t" << "year\t" << "day\t" << endl;
	multimap<int, int>::size_type  cnt = hold_id.count(key);
	multimap<int, int>::iterator  iter = hold_id.find(key);
	for (; cnt > 0; cnt--, iter++)
	{
		int year, day;

		year = (iter->second) / 360;
		day = (iter->second) - year * 360;
		cout << iter->first << "\t" << year << "\t" << day << endl;
		//cout << iter->first << " " << iter->second << endl;
	}
	cout << endl;
}
/*void Holder::show_value_to_key(int key) {
	//multimap<int, int>::iterator it,is;
	//it = hold_id.begin();
	//is = hold_value_to_key.begin();
	/*while (it != hold_id.end())
	{
		//cout << it->first << " " << it->second;
		int a, b;
		a = it->second;
		b = it->first;
		hold_value_to_key.insert(make_pair(a,b));//��һ��map���淴ת��hold_id
		it++;
		//is++;
		//cout << endl;
	}*/
	/*cout << "ID\t" << "year\t" << "day\t" << endl;
	multimap<int, int>::size_type  cnt = hold_value_to_key.count(5863);
	multimap<int, int>::iterator  iter = hold_value_to_key.find(5863);
	for (; cnt > 0; cnt--, iter++)
	{
		/*int year, day;

		year = (iter->first) / 360;
		day = (iter->first) - year * 360;
		cout << iter->second << "\t" << year << "\t" << day << endl;*/
		//cout << iter->first << " " << iter->second << endl;
		/*for (; cnt > 0; cnt--, iter++)
		{
			cout << iter->first << " " << iter->second << endl;
		}
	}
	cout << endl;
}*/
void Holder::test() {
	multimap<int, int>::iterator it;
	it = hold_id.begin();
	cout << "hold_id_map_test" << endl;
	while (it != hold_id.end())
	{
		cout << it->first<< " " <<  it->second;
		it++;
		cout << endl;
	}
	multimap<int, int>::iterator im;
	im = hold_value_to_key.begin();
	cout << "hold_value__to_key_map_test" << endl;
	while (im != hold_value_to_key.end())
	{
		cout << im->first << " " << im->second;
		im++;
		cout << endl;
	}
	cout << "��ͬ��ֵ����,Ĭ�ϲ��Լ�ֵ12" << endl;
	multimap<int, int>::size_type  cnt = hold_id.count(12);
	multimap<int, int>::iterator  iter = hold_id.find(12);
	for (; cnt > 0; cnt--, iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
	cout << endl;
	cout << "��ͬvalueֵ����,Ĭ�ϲ��Լ�ֵ5863" << endl;
	multimap<int, int>::size_type  cmb = hold_value_to_key.count(5863);
	multimap<int, int>::iterator  imb = hold_value_to_key.find(5863);
	for (; cmb > 0; cmb--, imb++)
	{
		cout << imb->first << " " << imb->second << endl;
	}
	cout << endl;
}
void Holder::show_value_to_key(int m) {
	multimap<int, int>::size_type  cmb = hold_value_to_key.count(m);
	multimap<int, int>::iterator  imb = hold_value_to_key.find(m);
	cout << "������Ҫ��ѯ��data(һ������)"<<endl;
	for (; cmb > 0; cmb--, imb++)
	{
		int s_year, s_day;
		s_year = (imb->first) / 360;
		s_day = imb->first - 360 * s_year;
		cout << imb->second << "\t" << s_year <<"\t"<<s_day<< endl;
		cout << "count" << cmb << endl;
	}
	cout << endl;
}
//���÷�ת��map����ѯ�ض����ڣ�����Щ����
//���浽һ���µ�map�У�(��map��Ϊ��ת��������ʽ)
//Ȼ������count()�����ĵ���Ӧid�ķ��ʴ��������½�
//һ��map����Ϊid��ֵΪ���ʴ���
void Holder::show_data_sort(int u, int o) {//u�ǲ�ѯ�����õģ�o�������޶�����������
	multimap<int, int>::size_type  cmb = hold_value_to_key.count(u);
	multimap<int, int>::iterator  imb = hold_value_to_key.find(u);
	for (; cmb > 0; cmb--, imb++)
	{
		int i, j;
		i = imb->second;
		j = imb->first;
		hold_f.insert(make_pair(i, j));//��һ����ת������map
		//cout << imb->first << " " << imb->second << endl;
	}
	/*test   hold_f   ���Գɹ�������hold_f�ɹ���ת��
	cout << "ID\t" << "year\t" << "day\t" << endl;
	for (multimap<int, int>::iterator i = hold_f.begin(); i != hold_f.end(); i++) {



		cout << i->first << "\t" << i->second << endl;
	}
}*/
	//�����µ�map��ÿ��key����count�ĵ���Ӧ�Ĵ��������������������µ�map
	multimap<int, int>::iterator im;
	im = hold_f.begin();
	
	while (im != hold_f.end())
	{
	
		int i,k,l;
		i = im->first;
		l = im->second;
		multimap<int, int>::size_type  j = hold_f.count(i);
		//cout << im->first << " " << im->second;
		k = j;
		//cout << "cout" << k << endl;//������
		hold_s.insert(make_pair(i, k));
		im++;
		//cout << endl;
	}
	//����o��ֵ����ʾ
	cout << "id" << "\t" << "����" << endl;
	int yu = 0;
	for (map<int, int>::iterator i = hold_s.begin(); i != hold_s.end()&&yu<o;yu++, i++) {
		
		//if ((i->first)!=((--i)->first)) {
			//i++;
			
			cout << i->first << "\t" << i->second << endl;
		//}
	}
}
