#include "./rapidjson-1.1.0/include/rapidjson/document.h"
#include "./rapidjson-1.1.0/include/rapidjson/filereadstream.h"
// #include "./rapidjson-1.1.0/include/rapidjson/document.h"
// #include ""

using namespace rapidjson;
using namespace std;

void printer_name(auto &v, int level);
void printer_value(auto &v, int level);

// void print_array(Value::GenericValue v)
// {
// 	if (v.IsInt())
// 		printf("%d", v.GetInt());
// 	else if (v.IsBool())
// 		printf("%s", v.GetBool() ? "true" : "false");
// 	else if (v.IsString())
// 		printf("%s", v.GetString());
// 	else if (v.IsDouble())
// 		printf("%lf", v.GetDouble());
// 	else if (v.IsArray()){
// 		for (auto &m : v.GetArray())
// 			print_array(m);
// 	}
// 	else if (v.IsObject()){
// 		for (auto &m : v.GetObject())
// 			print_value(m);
// 	}
// }
// void print_value(Value::ConstMemberIterator v)
void printer_array(auto &v, int level)
{
	// for (int i=0; i<level; i++)
	// 	printf("\t");
	if (v.IsInt())
		printf("%d", v.GetInt());
	else if (v.IsBool())
		printf("%s", v.GetBool() ? "true" : "false");
	else if (v.IsString())
		printf("%s", v.GetString());
	else if (v.IsDouble())
		printf("%lf", v.GetDouble());
}

void printer_name(auto &v, int level)
{
	// for (int i=0; i<level; i++)
	// 	printf("\t");
	if (v.value.IsInt())
		printf("%d", v.value.GetInt());
	else if (v.value.IsBool())
		printf("%s", v.value.GetBool() ? "true" : "false");
	else if (v.value.IsString())
		printf("%s", v.value.GetString());
	else if (v.value.IsDouble())
		printf("%lf", v.value.GetDouble());
	else if (v.value.IsArray()){
		for (auto &m : v.value.GetArray()){
			//if (!m.GetString())
				// printf("%d", m.GetInt());
			// printer_name(m);
			// printf("%s", ":");
			// printer_value(m);
			// printf("\n");
			printer_array(m, level);
			printf(",");
		}
	}
	else if (v.value.IsObject()){
		printf("\n");
		
		for (auto &m : v.value.GetObject()){
			for (int i=0; i<level+1; i++)
				printf("\t");
			printer_value(m, level+1);
			printf("%s", ":");
			printer_name(m, level+1);
			printf("\n");
			// printf("%s:%d\n", m.name.GetString(), m.value.GetInt());
		}
	}
}

// void print_name(Value::ConstMemberIterator v)
void printer_value(auto &v, int level)
{
	if (v.name.IsInt())
		printf("%d", v.name.GetInt());
	else if (v.name.IsBool())
		printf("%s", v.name.GetBool() ? "true" : "false");
	else if (v.name.IsString())
		printf("%s", v.name.GetString());
	else if (v.name.IsDouble())
		printf("%lf", v.name.GetDouble());
}


void print_value(Value::ConstMemberIterator v, int level)
// void print_name(auto &v)
{
	for (int i=0; i<level; i++)
		printf("\t");
	if (v->value.IsInt())
		printf("%d", v->value.GetInt());
	else if (v->value.IsBool())
		printf("%s", v->value.GetBool() ? "true" : "false");
	else if (v->value.IsString())
		printf("%s", v->value.GetString());
	else if (v->value.IsDouble())
		printf("%lf", v->value.GetDouble());
	else if (v->value.IsArray()){
		for (auto &m : v->value.GetArray()){
			//if (!m.GetString())
				//  printf("%d", m.GetInt());
			// printer_name(m);
			// printf("%s", ":");
			// printer_value(m);
			// printf("\n");
			printer_array(m, level);
			printf(",");
		}
	}
	else if (v->value.IsObject()){
		printf("\n");

		for (auto &m : v->value.GetObject()){
			for (int i=0; i<level+1; i++)
				printf("\t");
			printer_value(m, level+1);
			printf("%s", ":");
			printer_name(m, level+1);
			printf("\n");
			// printf("%s:%d\n", m.name.GetString(), m.value.GetInt());
		}
	}
}

void print_name(Value::ConstMemberIterator v, int level)
// void print_value(auto &v)
{
	for (int i=0; i<level; i++)
		printf("\t");
	if (v->name.IsInt())
		printf("%d", v->name.GetInt());
	else if (v->name.IsBool())
		printf("%s", v->name.GetBool() ? "true" : "false");
	else if (v->name.IsString())
		printf("%s", v->name.GetString());
	else if (v->name.IsDouble())
		printf("%lf", v->name.GetDouble());
}


int main()
{
	FILE *fp = fopen("test.json", "r");

	char readbuffer[65536];
	FileReadStream is(fp, readbuffer, sizeof(readbuffer));

	int level = 0;

	Document doc;
	doc.ParseStream(is);
	for(Value::ConstMemberIterator itr=doc.MemberBegin();
		itr != doc.MemberEnd(); ++itr)
		{
			// printf("%s\t", itr->name.GetString());
			// //printf("%s\t", itr->value.GetString());
			// if (itr->value.IsString())
			// 	printf("%s\t", itr->value.GetString());
			// if (itr->value.IsArray()){
			// 	for (auto& v : itr->value.GetArray())
			// 		printf("\n%d", v.GetInt());
			// }
			// if (itr->value.IsObject()){
			// 	for (auto& m : itr->value.GetObject()){
			// 		printf("\n%s\t", m.name.GetString());
			// 		if (m.value.IsInt())
			// 			printf("\n%d\t", m.value.GetInt());
			// 		else
			// 			printf("\n%s\t", m.value.GetString());
			// 	}
			// }
				print_name(itr, level);
				printf("%s", ":");
				print_value(itr, level);
				printf("\n");
		}
}