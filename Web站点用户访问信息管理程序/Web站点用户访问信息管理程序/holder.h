#pragma once
#include<map>
#include"fileread.h"


using namespace std;
extern Fileread fileread;
class Holder {
public:
	/*���г����������ָ����ĳһ������з����ߡ�
���г�ĳ��ĳ������з����ߡ�
���ó�ĳ����������ĳ���ĳ��ķ��ʴ�����
���г�ĳ���ĳ����ǰn��������Ƶ���ķ����ߣ�n���û�ָ����
���ֱ���IP��ַ���������ڻ�������Ϊ˳���ļ��е������������׼�������
*/
	/*map<int, int*/ void sort_date();
	void show_date();//��interface�н�����show()չʾ����õ���Ϣ
	void show_id();//show()��������������
	void show_key(int );
	void show_value_to_key(int);
	void show_data_sort(int,int);
	void test();
	multimap<int, int> hold_date;//�������ݰ���������
	multimap<int, int> hold_id;//�������ݰ�id����mapĬ�ϰ�key���򣬹�ֱ�ӽ������map��ֵ����
	multimap<int, int> hold_day;
	multimap<int, int> hold_person;//û�õģ���Ҫ��
	multimap<int, int> hold_value_to_key;
	multimap<int, int> hold_f;
	map<int, int> hold_s;
	//�����ź����map��
};

