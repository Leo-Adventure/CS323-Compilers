#include "type.hpp"
#include "unordered_map"
using namespace std;

class TAC;
enum class Operator;

extern vector<TAC *> tac_vector;
extern unordered_map<string, int> table;

const int BASIC_SIZE = 4;

string addr2str(int addr);
string operator2str(Operator op);
int getOffSet(GlobalType* global_type, string name);
string getNodeName(Node* node);

class TAC
{
public:
    int address;
    string name;
    GlobalType *type;
    bool swap_flag = false;
    TAC()
    {
        swap_flag = false;
    }
    virtual string to_string()
    {
        return "";
    }
    virtual int generate_ID()
    {
        int ID = tac_vector.size();
        tac_vector.push_back(this);
        return ID;
    }
};

class LabelTAC : public TAC
{
public:
    LabelTAC(int address)
    {
        TAC::address = address;
    }
    string to_string()
    {
        char buffer[1024];
        sprintf(buffer, "LABEL label%d :", TAC::address);
        return buffer;
    }
};

class DecTAC : public TAC
{
public:
    vector<int> sizes;
    vector<int> suffix;
    DecTAC(int address, GlobalType *type, string name, vector<int> sizes)
    {
        TAC::address = address;
        TAC::type = type;
        TAC::name = name;
        this -> sizes = sizes;
        int offset = 1;
        for(int i = sizes.size() - 1; i >= 0; i--){
            suffix.push_back(offset);
            offset *= sizes[i];
        }
    }

    string to_string(){
        char buffer[1024];
        int size = 1;
        // printf("In tostring, the size of this->sizes = %d\n", this->sizes.size());
        for(int i = 0; i < this->sizes.size(); i++){
            size *= this->sizes[i];
        }
        // 注意这里要更改为合适的size
        // printf("Basicsize = %d, size = %d\n", BASIC_SIZE, size);
        if(type != nullptr && type->category == STRUCTURE){
            size = type->size;
        }
        sprintf(buffer, "DEC t%d %d", TAC::address, BASIC_SIZE * size);
        return buffer;
    }
};

class FunctionTAC: public TAC {
public:
    FunctionTAC(int address, string name){
        TAC::address = address;
        TAC::name = name;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "FUNCTION %s :", TAC::name.c_str());
        return buffer;
    }
};


class AssignTAC: public TAC{
public:
    int right_address;
    AssignTAC(int address, int right_address){
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "t%d := %s", TAC::address, addr2str(right_address).c_str());
        return buffer;
    }
};

class AssignAddressTAC: public TAC{
public:
    int right_address;
    AssignAddressTAC(int address, int right_address){
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "t%d := &t%d", TAC::address, right_address);
        return buffer;
    }
};

class AssignValueTAC: public TAC{
public:
    int right_address;
    AssignValueTAC(int address, int right_address){
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "t%d := *t%d", TAC::address, right_address);
        return buffer;
    }
};


class CopyValueTAC: public TAC{
public:
    int right_address;
    CopyValueTAC(int address, int right_address){
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "*t%d := t%d", TAC::address, right_address);
        return buffer;
    }
};

class ArithmeticTAC: public TAC{
public:
    Operator op;
    int left_address;
    int right_address;
    ArithmeticTAC(int address, Operator op, int left_address, int right_address){
        TAC::address = address;
        this->op = op;
        this->left_address = left_address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "t%d := %s %s %s", TAC::address, addr2str(left_address).c_str(), operator2str(op).c_str(), addr2str(right_address).c_str());
        return buffer;
    }
};


class GOTOTAC: public TAC{
public:
    int* label;
    GOTOTAC(int address, int* label){
        TAC::address = address;
        this->label = label;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "GOTO label%d", *label);
        return buffer;
    }
};

class IFTAC: public TAC{
public:
    int* label;
    Operator op;
    int left_address;
    int right_address;
    IFTAC(int address, Operator op, int left_address, int right_address, int* label){
        TAC::address = address;
        this->op = op;
        this->left_address = left_address;
        this->right_address = right_address;
        this->label = label;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "IF t%d %s t%d GOTO label%d", left_address, operator2str(op).c_str(), right_address, *label);
        return buffer;
    }
};

class ReturnTAC: public TAC{
public:
    int right_address;
    ReturnTAC(int address, int right_address){
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "RETURN %s", addr2str(right_address).c_str());
        return buffer;
    }
};


class ParamTAC: public TAC{
public:
    vector<int> suffix;
    vector<int> sizes;
    ParamTAC(int address, GlobalType *type, vector<int> sizes){
        TAC::address = address;
        TAC::type = type;
        this->sizes = vector<int>();
        this->sizes.insert(this->sizes.end(), sizes.begin(), sizes.end());
        int totle = 1;
        for(int i = sizes.size() - 1; i >= 0; --i){
            suffix.push_back(totle);
            totle *= sizes[i];
        }
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "PARAM t%d", TAC::address);
        return buffer;
    }
};

class ArgTAC: public TAC{
public:
    int right_address;
    ArgTAC(int address, int right_address){
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "ARG t%d", right_address);
        return buffer;
    }
};

class CallTAC: public TAC{
public:
    string label;
    CallTAC(int address, string label){
        TAC::address = address;
        this->label = label;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "t%d := CALL %s", TAC::address, label.c_str());
        return buffer;
    }
};

class ReadTAC: public TAC{
public:
    ReadTAC(int address){
        TAC::address = address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "READ t%d", TAC::address);
        return buffer;
    }
};

class WriteTAC: public TAC{
public:
    int right_address;
    WriteTAC(int address, int right_address){
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[1024];
        sprintf(buffer, "WRITE t%d", right_address);
        return buffer;
    }
};





int inter_exp(Node *node, bool single = false);
vector<int> inter_args(Node *node);

void inter_init();
void inter_program(Node *root);
void inter_extDefList(Node *node);
void inter_extDecList(Node *node, GlobalType * type);
void inter_extDef(Node *node);
GlobalType *inter_specifier(Node *node);
GlobalType *inter_type(Node *node);
GlobalType *inter_structSpecifier(Node *node);
void inter_func(Node *node, GlobalType *type);
void inter_compSt(Node *node);
void inter_defList(Node *node);
void inter_def(Node *node);
void inter_decList(Node *node, GlobalType *type);
void inter_stmt(Node *node);
void inter_stmtList(Node *node);
void inter_dec(Node *node, GlobalType *type);
TAC* inter_varDec(Node *node, GlobalType* type);
void inter_varList(Node *node);
void inter_paramDec(Node *node);

int getIR(string name);
void putIR(string name, int id);
int genid(TAC *tac);
int *genlist(int id = tac_vector.size() + 1);

void inter_IF(int id, int tbranch, int fbranch);
void inter_WHILE(vector<int>* stat_vec, int end, int target);
GlobalType *checkType(Node *node);

float formatPaser(string name, string value);
