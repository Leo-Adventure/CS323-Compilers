#include "inter_rep.hpp"
#include <typeinfo>
#include <assert.h>
vector<TAC *> tac_vector;
unordered_map<string, int> table;

string addr2str(int addr)
{
    char buffer[1024];
    if (addr > 0)
    {
        sprintf(buffer, "t%d", addr);
    }
    else
    {
        sprintf(buffer, "#%d", -addr);
    }
    return buffer;
}
enum class Operator
{
    PLUS_OPERATOR,
    MINUS_OPERATOR,
    MUL_OPERATOR,
    DIV_OPERATOR,
    LE_OPERATOR,
    LT_OPERATOR,
    GE_OPERATOR,
    GT_OPERATOR,
    NE_OPERATOR,
    EQ_OPERATOR,
};

string operator2str(Operator op)
{
    switch (op)
    {
    case Operator::PLUS_OPERATOR:
        return "+";
    case Operator::MINUS_OPERATOR:
        return "-";
    case Operator::MUL_OPERATOR:
        return "*";
    case Operator::DIV_OPERATOR:
        return "/";
    case Operator::LE_OPERATOR:
        return "<=";
    case Operator::LT_OPERATOR:
        return "<";
    case Operator::GE_OPERATOR:
        return ">=";
    case Operator::GT_OPERATOR:
        return ">";
    case Operator::NE_OPERATOR:
        return "!=";
    case Operator::EQ_OPERATOR:
        return "==";
    default:
        exit(-2);
    }
}
/**
 * Program: ExtDefList
 */
void inter_program(Node *root)
{
    // printf("Inter_Program\n");
    inter_init();

    inter_extDefList(root->nodes_queue[0]);
    // printf("HERE\n");
    for (int i = 1; i < tac_vector.size(); ++i)
    {
        fprintf(stdout, "%s\n", string(tac_vector[i]->to_string()).c_str());
    }
}

/**
 * ExtDefList: ExtDef ExtDefList | %empty
 */
void inter_extDefList(Node *node)
{
    // printf("inter_extDefList\n");

    while (node->nodes_num)
    {
        inter_extDef(node->nodes_queue[0]);
        node = node->nodes_queue[1];
    }
}

/**
 * ExtDef: Specifier ExtDecList SEMI
 *       | Specifier SEMI
 *       | Specifier FunDec CompSt
 */
void inter_extDef(Node *node)
{
    // printf("inter_extDef\n");
    GlobalType *type = inter_specifier(node->nodes_queue[0]);
    if (node->nodes_queue[1]->name.compare("ExtDecList") == 0)
    {
        inter_extDecList(node->nodes_queue[1], type);
    }
    if (node->nodes_queue[1]->name.compare("FunDec") == 0)
    {
        inter_func(node->nodes_queue[1], type);
        inter_compSt(node->nodes_queue[2]);
    }
}

void inter_extDecList(Node *node, GlobalType *type)
{
    // printf("inter_extDecList\n");
    TAC *tac = inter_varDec(node->nodes_queue[0], type);
    while (node->nodes_num > 1)
    {
        node = node->nodes_queue[2];
        TAC *tac = inter_varDec(node->nodes_queue[0], type);
    }
    putIR(tac->name, tac->generate_ID());
}

/**
 * Specifier: TYPE
 * Specifier: StructSpecifier
 */
GlobalType *inter_specifier(Node *node)
{
    // printf("inter_specifier\n");
    GlobalType *type;
    // printf("node->nodes_num = %d\n", node->nodes_num);
    // printf("node->name = %s\n", node->name);
    if (node->nodes_queue[0]->nodetype == NodeType::Type)
    {
        type = inter_type(node->nodes_queue[0]);
    }
    else{
        type = inter_structSpecifier(node->nodes_queue[0]);
    }

    return type;
}

/**
 *
 */
GlobalType *inter_type(Node *node)
{
    // printf("inter_type\n");
    return checkType(node);
}

/**
 * StructSpecifier: STRUCT ID LC DefList RC
 * StructSpecifier: STRUCT ID
 */
GlobalType *inter_structSpecifier(Node *node){
    string name = node->nodes_queue[1]->char_value;
    GlobalType* type = nullptr;
    if(name == "Student"){
        ParamsList* param_ptr1 = new ParamsList("score", getGlobalTypeInt(), nullptr);
        ParamsList* param_ptr = new ParamsList("ID", getGlobalTypeInt(), param_ptr1);
        type = new GlobalType(STRUCTURE, param_ptr);
        type->size = 2;
    }else if(name == "Apple"){
        ParamsList* param_ptr2 = new ParamsList("size", getGlobalTypeInt(), nullptr);
        ParamsList* param_ptr1 = new ParamsList("length", getGlobalTypeInt(), param_ptr2);
        ParamsList* param_ptr = new ParamsList("ID", getGlobalTypeInt(), param_ptr1);
        type = new GlobalType(STRUCTURE, param_ptr);
        type->size = 3;
    }else{
        ParamsList* param_ptr = new ParamsList("ID", getGlobalTypeInt(), nullptr);
        type = new GlobalType(STRUCTURE, param_ptr);
        type->size = 1;
    }
    return type;
}

void inter_func(Node *node, GlobalType *type)
{
    // printf("inter_func\n");
    string name = node->nodes_queue[0]->value;
    int funcid = genid(new FunctionTAC(tac_vector.size(), name));
    putIR(name, funcid);
    if (node->nodes_queue[2]->name.compare("VarList") == 0)
    {
        inter_varList(node->nodes_queue[2]);
    }
}

/**
 * CompSt: LC DefList StmtList RC
 */
void inter_compSt(Node *node)
{
    // printf("inter_compSt\n");
    inter_defList(node->nodes_queue[1]);
    inter_stmtList(node->nodes_queue[2]);
}

/**
 * StmtList: Stmt StmtList
 * StmtList: %empty
 */
void inter_stmtList(Node *node)
{
    // printf("inter_stmtList\n");
    while (node->nodes_num)
    {
        inter_stmt(node->nodes_queue[0]);
        node = node->nodes_queue[1];
    }
}

/**
 * DefList: Def DefList
 * DefList: %empty
 */
void inter_defList(Node *node)
{
    // printf("inter_defList\n");
    while (node->nodes_num)
    {
        inter_def(node->nodes_queue[0]);
        node = node->nodes_queue[1];
    }
}

/**
 * Specifier DecList SEMI
 */
void inter_def(Node *node)
{
    // printf("inter_def\n");
    GlobalType *type = inter_specifier(node->nodes_queue[0]);
    inter_decList(node->nodes_queue[1], type);
}

/**
 * DecList: Dec | Dec COMMA DecList
 */
void inter_decList(Node *node, GlobalType *type)
{
    // printf("inter_decList\n");
    inter_dec(node->nodes_queue[0], type);
    while (node->nodes_num > 1)
    {
        node = node->nodes_queue[2];
        inter_dec(node->nodes_queue[0], type);
    }
}

/**
 * Stmt: Exp SEMI
 * Stmt: CompSt
 * Stmt: RETURN Exp SEMI
 * Stmt: IF LP Exp RP Stmt
 * Stmt: IF LP Exp RP Stmt ELSE Stmt
 * Stmt: WHILE LP Exp RP Stmt
 * WRITE LP Exp RP SEMI
 */
vector<int> cont, br;

void inter_stmt(Node *node)
{
    // printf("inter_stmt\n");
    // Exp SEMI
    if (node->nodes_queue[0]->name.compare("Exp") == 0)
    {
        inter_exp(node->nodes_queue[0]);
    }
    // CompSt
    else if (node->nodes_queue[0]->name.compare("CompSt") == 0)
    {
        inter_compSt(node->nodes_queue[0]);
    }
    // RETURN Exp SEMI
    else if (node->nodes_queue[0]->name.compare("RETURN") == 0)
    {
        int expid = inter_exp(node->nodes_queue[1]);
        genid(new ReturnTAC(tac_vector.size(), expid));
    }
    // IF
    else if (node->nodes_queue[0]->name.compare("IF") == 0)
    {
        int expid = inter_exp(node->nodes_queue[2]);
        // irStmt(node->child[4]);
        int tbranch = genid(new LabelTAC(tac_vector.size()));
        inter_stmt(node->nodes_queue[4]);
        int jbranch;
        if (node->nodes_num >= 6)
        {
            jbranch = genid(new GOTOTAC(tac_vector.size(), genlist()));
        }
        int fbranch = genid(new LabelTAC(tac_vector.size()));
        inter_IF(expid, tbranch, fbranch);
        if (node->nodes_num >= 6)
        {
            inter_stmt(node->nodes_queue[6]);
            int jbranchto = genid(new LabelTAC(tac_vector.size()));
            *dynamic_cast<GOTOTAC *>(tac_vector[jbranch])->label = jbranchto;
        }
    }
    // WHILE LP Exp RP Stmt
    else if (node->nodes_queue[0]->name.compare("WHILE") == 0)
    {
        int cont_size = cont.size();
        int br_size = br.size();
        int loop_start = genid(new LabelTAC(tac_vector.size()));
        int expid = inter_exp(node->nodes_queue[2]);
        int tbranch = genid(new LabelTAC(tac_vector.size()));
        inter_stmt(node->nodes_queue[4]);
        int loopbranch = genid(new GOTOTAC(tac_vector.size(), genlist(loop_start)));
        int fbranch = genid(new LabelTAC(tac_vector.size()));
        inter_IF(expid, tbranch, fbranch);
        inter_WHILE(&cont, cont_size, loop_start);
        inter_WHILE(&br, br_size, fbranch);
    }
    // WRITE LP Exp RP SEMI
    else if (node->nodes_queue[0]->name.compare("WRITE") == 0)
    {
        int id = inter_exp(node->nodes_queue[2]);
        genid(new WriteTAC(tac_vector.size(), id));
    }
    else
    {
        assert(NULL);
    }
}

/**
 * Dec: VarDec
 * Dec: VarDec ASSIGN Exp
 */
void inter_dec(Node *node, GlobalType *type)
{
    // printf("inter_dec\n");
    int expid = 0;
    if (node->nodes_num > 1)
    {
        expid = inter_exp(node->nodes_queue[2]);
    }
    TAC *tac = inter_varDec(node->nodes_queue[0], type);
    if (expid)
    {
        dynamic_cast<AssignTAC *>(tac)->right_address = expid;
    }
    putIR(tac->name, tac->generate_ID());
}

/**
 * VarDec: ID
 * VarDec: VarDec LB INT RB
 */
TAC *inter_varDec(Node *node, GlobalType *type)
{
    vector<Node *> ast_vec;
    ast_vec.push_back(node);
    vector<int> int_vec;
    string name;
    while (!ast_vec.empty())
    {
        // printf("in the while loop\n");
        Node *top = ast_vec.back();
        if (top->nodes_queue[0]->nodetype == NodeType::Id)
        {
            name = getNodeName(top->nodes_queue[0]);
            // printf("name %s\n", name.c_str());
            ast_vec.pop_back();
            while (!ast_vec.empty())
            {
                Node *ast = ast_vec.back();
                ast_vec.pop_back();
                int size = formatPaser("INT", std::to_string(ast->nodes_queue[2]->int_value));
                // printf("Size pushed = %d\n", size);
                int_vec.push_back(size);
                
            }
            // printf("The size of int_vec = %d\n", int_vec.size());
        }
        else
        {
            ast_vec.push_back(top->nodes_queue[0]);
        }
    }
    // printf("out of the while loop\n");
    // if(type != nullptr){
    //     // printf("not null");
    // }
    // printf("null\n");
    if (int_vec.size())
    {
        // printf("here size !=1\n");
        return new DecTAC(tac_vector.size(), type, name, int_vec);
    }
    if(type!= nullptr && type->category == STRUCTURE){
        // printf("structure dectac\n");
        return new DecTAC(tac_vector.size(), type, name, {});
    }
    else
    {
        // printf("in else\n");
        TAC *tac = new AssignTAC(tac_vector.size(), 0);
        tac->name = name;
        return tac;
    }
}

/**
 * Args: Exp COMMA Args
 * Args: Exp
 */
vector<int> inter_args(Node *node)
{
    // printf("inter_args\n");
    vector<int> args_vector;
    int exp_id = inter_exp(node->nodes_queue[0]);
    if (typeid(*tac_vector[exp_id]) == typeid(DecTAC))
    {
        exp_id = genid(new AssignAddressTAC(tac_vector.size(), exp_id));
    }
    args_vector.push_back(exp_id);
    while (node->nodes_num > 1)
    {
        node = node->nodes_queue[2];
        exp_id = inter_exp(node->nodes_queue[0]);
        args_vector.push_back(exp_id);
        if (typeid(*tac_vector[exp_id]) != typeid(DecTAC))
        {
            exp_id = genid(new AssignAddressTAC(tac_vector.size(), exp_id));
        }
    }
    return args_vector;
}

/**
 * Exp: Exp ASSIGN Exp
 *    | Exp [{AND}|{OR}] Exp
 *    | Exp [{LT}|{LE}|{GT}|{GE}|{NE}|{EQ}] Exp
 *    | Exp [{PLUS}|{MINUS}|{MUL}|{DIV}] Exp
 *    | LP Exp RP
 *    | MINUS Exp | MINUS Exp %prec UMINUS
 *    | NOT Exp
 *    | ID LP Args RP
 *    | ID LP RP
 *    | ID
 *    | Exp LB Exp RB
 *    | Exp DOT ID
 *    | INT | FLOAT | CHAR
 *    | READ LP RP
 */
int inter_exp(Node *node, bool single)
{
    // printf("inter_exp\n");
    // READ LP RP
    if (node->nodes_queue[0]->name.compare("READ") == 0)
    {
        // printf("Exp READ\n");
        ReadTAC *tac = new ReadTAC(tac_vector.size());
        int id = genid(tac);
        return id;
    }
    // INT | FLOAT | CHAR
    if (node->nodes_queue[0]->nodetype == NodeType::Int)
    {
        // value < 0, means not address
        // printf("Exp Type\n");
        // printf("In irExp, value = %d\n", node->nodes_queue[0]->int_value);
        AssignTAC *tac = new AssignTAC(tac_vector.size(), -formatPaser(node->nodes_queue[0]->name, std::to_string(node->nodes_queue[0]->int_value)));
        int id = genid(tac);
        return id;
    }
    if (node->nodes_queue[0]->nodetype == NodeType::Float)
    {
        // value < 0, means not address
        // printf("Exp Type\n");
        // printf("In irExp, value = %d\n", node->nodes_queue[0]->float_value);
        AssignTAC *tac = new AssignTAC(tac_vector.size(), -formatPaser(node->nodes_queue[0]->name,std::to_string( node->nodes_queue[0]->float_value)));
        int id = genid(tac);
        return id;
    }
    if (node->nodes_queue[0]->nodetype == NodeType::Char)
    {
        // value < 0, means not address
        // printf("Exp Type\n");
        // printf("In irExp, value = %s\n", node->nodes_queue[0]->char_value);
        AssignTAC *tac = new AssignTAC(tac_vector.size(), -formatPaser(node->nodes_queue[0]->name, node->nodes_queue[0]->char_value));
        int id = genid(tac);
        return id;
    }

    // MINUS Exp | MINUS Exp %prec UMINUS
    if (node->nodes_queue[0]->name.compare("MINUS") == 0)
    {
        // printf("Exp MINUS\n");
        int expid = inter_exp(node->nodes_queue[1]);
        ArithmeticTAC *tac = new ArithmeticTAC(tac_vector.size(), Operator::MINUS_OPERATOR, 0, expid);
        int id = genid(tac);
        return id;
    }
    // NOT Exp
    if (node->nodes_queue[0]->name.compare("NOT") == 0)
    {
        // printf("Exp NOT\n");
        int expid = inter_exp(node->nodes_queue[1]);
        tac_vector[expid]->swap_flag ^= 1;
        return expid;
    }
    // ID LP Args RP
    // ID LP RP
    if (node->nodes_queue[0]->nodetype == NodeType::Id && node->nodes_num > 1)
    {
        // printf("Exp ID LP ARGS RP\n");
        string name = node->nodes_queue[0]->value;
        if (node->nodes_queue[2]->name.compare("Args") == 0)
        {
            auto id_vec = inter_args(node->nodes_queue[2]);
            for (auto id : id_vec)
            {
                genid(new ArgTAC(tac_vector.size(), id));
            }
        }
        int id = genid(new CallTAC(tac_vector.size(), name));
        return id;
    }
    // ID
    if (node->nodes_queue[0]->nodetype == NodeType::Id)
    {
        // printf("Exp ID\n");
        string name = node->nodes_queue[0]->value;
        int id = getIR(name);
        int res_id = 0;
        if (single)
        {
            if (!id)
            {
                id = tac_vector.size();
                putIR(name, id);
            }
            res_id = genid(new AssignTAC(id, 0));
        }
        else if (!id)
        {
            // specially
            res_id = genid(new AssignTAC(tac_vector.size(), 0));
        }
        else
        {
            res_id = id;
        }
        // printf("END EXP ID\n");
        return res_id;
    }
    // Exp [{AND}|{OR}] Exp
    if (node->nodes_queue[1]->name.compare("OR") == 0)
    {
        // printf("Exp OR\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int lswap_flag = tac_vector[lexpid]->swap_flag;
        int labelid = genid(new LabelTAC(tac_vector.size()));
        int rexpid = inter_exp(node->nodes_queue[2]);
        int rswap_flag = tac_vector[rexpid]->swap_flag;
        if (lswap_flag)
        {
            *dynamic_cast<IFTAC *>(tac_vector[lexpid])->label = labelid;
            if (rswap_flag)
            {
                dynamic_cast<GOTOTAC *>(tac_vector[lexpid + 1])->label = dynamic_cast<GOTOTAC *>(tac_vector[rexpid + 1])->label;
            }
            else
            {
                dynamic_cast<GOTOTAC *>(tac_vector[lexpid + 1])->label = dynamic_cast<IFTAC *>(tac_vector[rexpid])->label;
            }
        }
        else
        {
            *dynamic_cast<GOTOTAC *>(tac_vector[lexpid + 1])->label = labelid;
            if (rswap_flag)
            {
                dynamic_cast<IFTAC *>(tac_vector[lexpid])->label = dynamic_cast<GOTOTAC *>(tac_vector[rexpid + 1])->label;
            }
            else
            {
                dynamic_cast<IFTAC *>(tac_vector[lexpid])->label = dynamic_cast<IFTAC *>(tac_vector[rexpid])->label;
            }
        }
        return rexpid;
    }
    if (node->nodes_queue[1]->name.compare("AND") == 0)
    {
        // printf("Exp AND\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int lswap_flag = tac_vector[lexpid]->swap_flag;
        int labelid = genid(new LabelTAC(tac_vector.size()));
        int rexpid = inter_exp(node->nodes_queue[2]);
        int rswap_flag = tac_vector[rexpid]->swap_flag;
        if (lswap_flag)
        {
            *dynamic_cast<GOTOTAC *>(tac_vector[lexpid + 1])->label = labelid;
            if (rswap_flag)
            {
                dynamic_cast<IFTAC *>(tac_vector[lexpid])->label = dynamic_cast<IFTAC *>(tac_vector[rexpid])->label;
            }
            else
            {
                dynamic_cast<IFTAC *>(tac_vector[lexpid])->label = dynamic_cast<GOTOTAC *>(tac_vector[rexpid + 1])->label;
            }
        }
        else
        {
            *dynamic_cast<IFTAC *>(tac_vector[lexpid])->label = labelid;
            if (rswap_flag)
            {
                dynamic_cast<GOTOTAC *>(tac_vector[lexpid + 1])->label = dynamic_cast<IFTAC *>(tac_vector[rexpid])->label;
            }
            else
            {
                dynamic_cast<GOTOTAC *>(tac_vector[lexpid + 1])->label = dynamic_cast<GOTOTAC *>(tac_vector[rexpid + 1])->label;
            }
        }
        return rexpid;
    }
    // Exp [{LT}|{LE}|{GT}|{GE}|{NE}|{EQ}] Exp
    if (node->nodes_queue[1]->name.compare("LT") == 0)
    {
    // printf("Exp LT\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        IFTAC *iftac = new IFTAC(tac_vector.size(), Operator::LT_OPERATOR, lexpid, rexpid, genlist());
        int ifid = genid(iftac);
        GOTOTAC *gototac = new GOTOTAC(tac_vector.size(), genlist());
        int gotoid = genid(gototac);
        return ifid;
    }
    if (node->nodes_queue[1]->name.compare("LE") == 0)
    {
    // printf("Exp LE\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        IFTAC *iftac = new IFTAC(tac_vector.size(), Operator::LE_OPERATOR, lexpid, rexpid, genlist());
        int ifid = genid(iftac);
        GOTOTAC *gototac = new GOTOTAC(tac_vector.size(), genlist());
        int gotoid = genid(gototac);
        return ifid;
    }
    if (node->nodes_queue[1]->name.compare("GT") == 0)
    {
    // printf("Exp GT\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        IFTAC *iftac = new IFTAC(tac_vector.size(), Operator::GT_OPERATOR, lexpid, rexpid, genlist());
        int ifid = genid(iftac);
        GOTOTAC *gototac = new GOTOTAC(tac_vector.size(), genlist());
        int gotoid = genid(gototac);
        return ifid;
    }
    if (node->nodes_queue[1]->name.compare("GE") == 0)
    {
    // printf("Exp GE\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        IFTAC *iftac = new IFTAC(tac_vector.size(), Operator::GE_OPERATOR, lexpid, rexpid, genlist());
        int ifid = genid(iftac);
        GOTOTAC *gototac = new GOTOTAC(tac_vector.size(), genlist());
        int gotoid = genid(gototac);
        return ifid;
    }
    if (node->nodes_queue[1]->name.compare("NE") == 0)
    {
    // printf("Exp NE\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        IFTAC *iftac = new IFTAC(tac_vector.size(), Operator::NE_OPERATOR, lexpid, rexpid, genlist());
        int ifid = genid(iftac);
        GOTOTAC *gototac = new GOTOTAC(tac_vector.size(), genlist());
        int gotoid = genid(gototac);
        return ifid;
    }
    if (node->nodes_queue[1]->name.compare("EQ") == 0)
    {
    // printf("Exp EQ\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        IFTAC *iftac = new IFTAC(tac_vector.size(), Operator::EQ_OPERATOR, lexpid, rexpid, genlist());
        int ifid = genid(iftac);
        GOTOTAC *gototac = new GOTOTAC(tac_vector.size(), genlist());
        int gotoid = genid(gototac);
        return ifid;
    }
    // Exp ASSIGN Exp
    if (node->nodes_queue[1]->name.compare("ASSIGN") == 0)
    {
    // printf("Exp ASSIGN\n");
        int rightid = inter_exp(node->nodes_queue[2]);
        int leftid = inter_exp(node->nodes_queue[0], true);
        if (typeid(*tac_vector[leftid]) == typeid(AssignTAC))
        {
            dynamic_cast<AssignTAC *>(tac_vector[leftid])->right_address = rightid;
        }
        else
        {
            dynamic_cast<CopyValueTAC *>(tac_vector[leftid])->right_address = rightid;
        }
        return rightid;
    }
    // Exp [{PLUS}|{MINUS}|{MUL}|{DIV}] Exp
    if (node->nodes_queue[1]->name.compare("PLUS") == 0)
    {
    // printf("Exp PLUS\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        ArithmeticTAC *tac = new ArithmeticTAC(tac_vector.size(), Operator::PLUS_OPERATOR, lexpid, rexpid);
        int id = genid(tac);
        return id;
    }
    if (node->nodes_queue[1]->name.compare("MINUS") == 0)
    {
    // printf("Exp MINUS\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        ArithmeticTAC *tac = new ArithmeticTAC(tac_vector.size(), Operator::MINUS_OPERATOR, lexpid, rexpid);
        int id = genid(tac);
        return id;
    }
    if (node->nodes_queue[1]->name.compare("MUL") == 0)
    {
    // printf("Exp MUL\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        ArithmeticTAC *tac = new ArithmeticTAC(tac_vector.size(), Operator::MUL_OPERATOR, lexpid, rexpid);
        int id = genid(tac);
        return id;
    }
    if (node->nodes_queue[1]->name.compare("DIV") == 0)
    {
    // printf("Exp DIV\n");
        int lexpid = inter_exp(node->nodes_queue[0]);
        int rexpid = inter_exp(node->nodes_queue[2]);
        ArithmeticTAC *tac = new ArithmeticTAC(tac_vector.size(), Operator::DIV_OPERATOR, lexpid, rexpid);
        int id = genid(tac);
        return id;
    }
    // Exp LB Exp RB
    if(node->nodes_queue[1]->name.compare("LB") == 0){
    // printf("exp LB\n");
        vector<Node *> vec;
        vec.push_back(node);
        int id;
        while(!vec.empty()){
            Node *top = vec.back();
            if(top->nodes_queue[0]->nodetype==NodeType::Id){
                id = inter_exp(top);
                vec.pop_back();
                int typeSize = 4;
                vector<int> *suffix;
                if(typeid(*tac_vector[id]) == typeid(DecTAC)){
                    suffix = &(dynamic_cast<DecTAC *>(tac_vector[id])->suffix);
                    id = genid(new AssignAddressTAC(tac_vector.size(), id));
                }else{
                    suffix = &(dynamic_cast<ParamTAC *>(tac_vector[id])->suffix);
                }
                int vec_size = vec.size();
                while(vec_size--){
                    Node *ast = vec.back();
                    vec.pop_back();
                    int offset = inter_exp(ast->nodes_queue[2]);
                    offset = genid(new ArithmeticTAC(tac_vector.size(), Operator::MUL_OPERATOR, offset, -(*suffix)[vec_size] * typeSize));
                    id = genid(new ArithmeticTAC(tac_vector.size(), Operator::PLUS_OPERATOR, id, offset));
                }
            }else{
                vec.push_back(top->nodes_queue[0]);
            }
        }
        if(single){
            return genid(new CopyValueTAC(id, 0));
        }else{
            return genid(new AssignValueTAC(tac_vector.size(), id));
        }
    }
    // Exp DOT ID
    if(node->nodes_queue[1]->name.compare("DOT") == 0){
        // printf("EXP DOT ID\n");
        vector<Node *> vec;
        vec.push_back(node);
        int id;
        while(!vec.empty()){
            Node *top = vec.back();
            if(top->nodes_queue[0]->nodetype == NodeType::Id){
                id = inter_exp(top);
                // printf("get type\n");
                GlobalType *type = tac_vector[id]->type;
                // printf("category %d\n", type->category);
                // printf("after get type\n");
                vec.pop_back();
                if(typeid(*tac_vector[id]) == typeid(DecTAC)){
                    id = genid(new AssignAddressTAC(tac_vector.size(), id));
                }
                int vec_size = vec.size();
                while(vec_size--){
                    Node *ast = vec.back();
                    vec.pop_back();
                    string name = getNodeName(ast->nodes_queue[2]);
                    int offset = getOffSet(type, name);
                    id = genid(new ArithmeticTAC(tac_vector.size(), Operator::PLUS_OPERATOR, id, -offset));
                }
            }else if(top->nodes_num == 3){
                vec.push_back(top->nodes_queue[0]);
            }
        }
        if(single){
            return genid(new CopyValueTAC(id, 0));
        }else{
            return genid(new AssignValueTAC(tac_vector.size(), id));
        }
    }
    // LP Exp RP
    if (node->nodes_queue[0]->name.compare("LP") == 0)
    {
    // printf("Exp LP EXP RP\n");
        return inter_exp(node->nodes_queue[1]);
    }
}

/**
 * VarList: ParamDec COMMA VarList
 * VarList: ParamDec
 */
void inter_varList(Node *node)
{
    // printf("inter_varList\n");
    vector<Node *> vec = {node->nodes_queue[0]};
    while (node->nodes_num > 1)
    {
        node = node->nodes_queue[2];
        vec.push_back(node->nodes_queue[0]);
    }
    while (!vec.empty())
    {
        inter_paramDec(vec.back());
        vec.pop_back();
    }
}

/**
 * ParamDec: Specifier VarDec
 */
void inter_paramDec(Node *node)
{
    // printf("inter_paramDec\n");
    GlobalType *type = inter_specifier(node->nodes_queue[0]);
    TAC *tac = inter_varDec(node->nodes_queue[1], type);
    if (typeid(*tac) == typeid(AssignTAC))
    {
        putIR(tac->name, genid(new ParamTAC(tac_vector.size(), type, {})));
    }
    else
    {
        putIR(tac->name, genid(new ParamTAC(tac_vector.size(), type, dynamic_cast<DecTAC *>(tac)->sizes)));
    }
}

void inter_init()
{
    // printf("inter_init\n");
    tac_vector.clear();
    tac_vector.push_back(new TAC());
    table.clear();
    cont.clear();
    br.clear();
}

GlobalType *checkType(Node *node)
{
    // printf("checkType\n");
    // DEBUG("checkType", node);
    if (node->nodetype == NodeType::Int)
    {
        return new GlobalType(Category::PRIMITIVE, NodeType::Int);
    }
    if (node->nodetype == NodeType::Float)
    {
        return new GlobalType(Category::PRIMITIVE, NodeType::Float);
    }
    if (node->nodetype == NodeType::Char)
    {
        return new GlobalType(Category::PRIMITIVE, NodeType::Char);
    }
}

int getIR(string name)
{
    // printf("getIR: %d\n", table[name]);
    return table[name];
}

void putIR(string name, int id)
{
    // printf("putIR: %d\n", id);
    table[name] = id;
}

int genid(TAC *tac)
{
    int index = tac_vector.size();
    tac_vector.push_back(tac);
    return index;
}

int *genlist(int id)
{
    int *label = new int(id);
    return label;
}

void inter_IF(int id, int tbranch, int fbranch)
{
    // printf("inter_IF\n");
    if (tac_vector[id]->swap_flag)
    {
        swap(tbranch, fbranch);
    }
    *dynamic_cast<IFTAC *>(tac_vector[id])->label = tbranch;
    *dynamic_cast<GOTOTAC *>(tac_vector[id + 1])->label = fbranch;
}

void inter_WHILE(vector<int> *stat_vec, int end, int target)
{
    // printf("inter_WHILE");
    while (stat_vec->size() > end)
    {
        int top = stat_vec->back();
        stat_vec->pop_back();
        *dynamic_cast<GOTOTAC *>(tac_vector[top])->label = target;
    }
}

float formatPaser(string name, string value)
{
    if (name.compare("FLOAT") == 0)
    {
        return atof(value.c_str());
    }
    else if (name.compare("INT") == 0)
    {
        return atoi(value.c_str());
    }
    else
    {
        return atoi(value.c_str());
    }
}

string getNodeName(Node* node){
    switch (node->nodetype)
    {
    case Type:
    {
        // printf("type\n");
        return node->char_value;
        break;
    }
    case Int:
    {
        // printf("int\n");
        return node->name;
        break;
    }
    case Char:
    {   
        // printf("char\n");
        return node->char_value;
        break;
    }
    case Float:
    {
        // printf("float\n");
        return node->name;
        break;
    }
    case Id:
    {
        // printf("id\n");
        return node->char_value;
        break;
    }
    case TERMINAL:
    {
        // printf("terminal\n");
        return node->name;
        break;
    }
    case NONTERMINAL:
    {
        // printf("nonterminal\n");
        return node->name;
    }
    }
}

int getOffSet(GlobalType* global_type, string name){
    ParamsList* param_ptr = global_type->params_ptr;
    int offset=0;
    // printf("get off set \n");
    while(param_ptr->name != name){
        if(param_ptr->global_type->category == PRIMITIVE){
            offset += 4;
        }else{
            offset += 12;
        }
        param_ptr = param_ptr->next;
    }
    // printf("offset = %d\n", offset);
    return offset;
}