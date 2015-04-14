/*
 * ast.h
 *
 *  Created on: Nov 21, 2014
 *      Author: baki
 */

#ifndef SMT_AST_H_
#define SMT_AST_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include <vector>
#include <stdexcept>

#include "enums.h"
#include "typedefs.h"
#include "Visitable.h"
#include "Visitor.h"

namespace Vlab { namespace SMT {

class Script : public Visitable {
public:
	Script(CommandList_ptr);
	Script(const Script&);
	virtual Script_ptr clone() const;
	virtual ~Script();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	CommandList_ptr commands;

};

class Command : public Visitable {
public:
	Command();
	Command(type_CMD);
	Command(const Command&);
	virtual Command_ptr clone() const;
	virtual ~Command();
	virtual std::string str();
	type_CMD getType();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

private:
	type_CMD type;

};

/**
 * ( set-logic <symbol> )
 */
class SetLogic : public Command {
public:
	SetLogic(Primitive_ptr);
	SetLogic(const SetLogic&);
	virtual SetLogic* clone() const;
	virtual ~SetLogic();

	virtual void visit_children(Visitor_ptr);
	virtual std::string str() { return "set-logic"; };

	Primitive_ptr symbol;
};


/**
 * ( declare-fun <symbol> ( <sort>* ) <sort> )
 */
class DeclareFun : public Command {
public:
	DeclareFun(Primitive_ptr, SortList_ptr, Sort_ptr);
	DeclareFun(const DeclareFun&);
	virtual DeclareFun* clone() const;
	virtual ~DeclareFun();

	virtual void visit_children(Visitor_ptr);
	virtual std::string str() { return "declare-fun"; };

	Primitive_ptr symbol;
	SortList_ptr sort_list;
	Sort_ptr sort;
};

/**
 * ( assert <term> )
 */
class Assert : public Command {
public:
	Assert(Term_ptr);
	Assert(const Assert&);
	virtual Assert_ptr clone() const;
	virtual ~Assert();

	virtual void visit_children(Visitor_ptr);
	virtual std::string str() { return "assert"; };

	Term_ptr term;
};

/**
 * ( check-sat )
 */
class CheckSat : public Command {
public:
	CheckSat();
	CheckSat(const CheckSat&);
	virtual CheckSat* clone() const;
	virtual ~CheckSat();

	virtual void visit_children(Visitor_ptr);
	virtual std::string str() { return "check-sat"; };

};

/* ends commands */

/**
 *   "(" "!" term attribute_list_ ")"
 * | "(" "exists" "(" sorted_var_list_ ")" term ")"
 * | "(" "forall" "(" sorted_var_list_ ")" term ")"
 * | "(" "let" "(" var_binding_list_ ")" term ")"
 * | "(" "and" term_list_ ")"
 * | "(" "not" term_list_ ")"
 * | "(" "=" term_list_ ")"
 * | "(" ">" term_list_ ")"
 * | "(" ">=" term_list_ ")"
 * | "(" "<" term_list_ ")"
 * | "(" "<=" term_list_ ")"
 * | "(" "ite" term_list_ ")"
 * | "(" "re.++" term_list_ ")"
 * | "(" "re.or" term_list_ ")"
 * | "(" "str.++" term_list_ ")"
 * | "(" "str.in.re" term_list_ ")"
 * | "(" "str.len" term_list_ ")"
 * | "(" "str.to.re" term_list_ ")"
 * | "(" qual_identifier term_list_ ")"
 * | qual_identifier
 * | spec_constant
 */

class Term : public Visitable {
public:
	Term();
	Term(std::string name);
	Term(const Term&);
	virtual Term_ptr clone() const;
	virtual ~Term();

	virtual std::string str();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	std::string name;
};

class And : public Term {
public:
	And(TermList_ptr);
	And(const And&);
	virtual And_ptr clone() const;
	virtual ~And();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	TermList_ptr term_list;

};

class Not : public Term {
public:
	Not(Term_ptr);
	Not(const Not&);
	virtual Not_ptr clone() const;
	virtual ~Not();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr term;
};

class UMinus : public Term {
public:
	UMinus(Term_ptr);
	UMinus(const UMinus&);
	virtual UMinus_ptr clone() const;
	virtual ~UMinus();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr term;
};

class Minus : public Term {
public:
	Minus(Term_ptr, Term_ptr);
	Minus(const Minus&);
	virtual Minus_ptr clone() const;
	virtual ~Minus();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr left_term;
	Term_ptr right_term;
};

class Plus : public Term {
public:
	Plus(Term_ptr, Term_ptr);
	Plus(const Plus&);
	virtual Plus_ptr clone() const;
	virtual ~Plus();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr left_term;
	Term_ptr right_term;
};

class Eq : public Term {
public:
	Eq(Term_ptr, Term_ptr);
	Eq(const Eq&);
	virtual Eq_ptr clone() const;
	virtual ~Eq();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr left_term;
	Term_ptr right_term;
};

class Gt : public Term {
public:
	Gt(Term_ptr, Term_ptr);
	Gt(const Gt&);
	virtual Gt_ptr clone() const;
	virtual ~Gt();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr left_term;
	Term_ptr right_term;
};

class Ge : public Term {
public:
	Ge(Term_ptr, Term_ptr);
	Ge(const Ge&);
	virtual Ge_ptr clone() const;
	virtual ~Ge();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr left_term;
	Term_ptr right_term;
};

class Lt : public Term {
public:
	Lt(Term_ptr, Term_ptr);
	Lt(const Lt&);
	virtual Lt_ptr clone() const;
	virtual ~Lt();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr left_term;
	Term_ptr right_term;
};

class Le : public Term {
public:
	Le(Term_ptr, Term_ptr);
	Le(const Le&);
	virtual Le_ptr clone() const;
	virtual ~Le();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr left_term;
	Term_ptr right_term;
};

class Ite : public Term {
public:
	Ite(Term_ptr, Term_ptr, Term_ptr);
	Ite(const Ite&);
	virtual Ite_ptr clone() const;
	virtual ~Ite();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr cond;
	Term_ptr then_branch;
	Term_ptr else_branch;
};

class ReConcat: public Term {
public:
	ReConcat(TermList_ptr);
	ReConcat(const ReConcat&);
	virtual ReConcat_ptr clone() const;
	virtual ~ReConcat();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	TermList_ptr term_list;
	// ToRegex specifically
};

class ReOr: public Term {
public:
	ReOr(TermList_ptr);
	ReOr(const ReOr&);
	virtual ReOr_ptr clone() const;
	virtual ~ReOr();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	TermList_ptr term_list;
	// ToRegex specifically
};

class Concat : public Term {
public:
	Concat(TermList_ptr);
	Concat(const Concat&);
	virtual Concat_ptr clone() const;
	virtual ~Concat();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	TermList_ptr term_list;
};

class In : public Term {
public:
	In(Term_ptr, Term_ptr);
	In(const In&);
	virtual In_ptr clone() const;
	virtual ~In();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr left_term;
	Term_ptr right_term;
};

class Len : public Term {
public:
	Len(Term_ptr);
	Len(const Len&);
	virtual Len_ptr clone() const;
	virtual ~Len();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr term;
};

class ToRegex : public Term {
public:
	ToRegex(Term_ptr);
	ToRegex(const ToRegex&);
	virtual ToRegex_ptr clone() const;
	virtual ~ToRegex();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr term;
};

class UnknownTerm : public Term {
public:
	UnknownTerm(Term_ptr, TermList_ptr);
	UnknownTerm(const UnknownTerm&);
	virtual UnknownTerm* clone() const;
	virtual ~UnknownTerm();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Term_ptr term;
	TermList_ptr term_list;
};

/**
 * "(" "as" identifier sort ")"
 * | identifier
 */
class QualIdentifier : public Term {
public:
	QualIdentifier(Identifier_ptr);
	QualIdentifier(const QualIdentifier&);
	virtual QualIdentifier_ptr clone() const;
	virtual ~QualIdentifier();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	std::string getVarName();
	bool isSymbolic();

	Identifier_ptr identifier;

};

class AsQualIdentifier : public Term {
public:
	AsQualIdentifier(Identifier_ptr, Sort_ptr);
	AsQualIdentifier(const AsQualIdentifier&);
	virtual AsQualIdentifier_ptr clone() const;
	virtual ~AsQualIdentifier();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Identifier_ptr identifier;
	Sort_ptr sort;
};

class TermConstant : public Term {
public:
	TermConstant(Primitive_ptr);
	TermConstant(const TermConstant&);
	virtual TermConstant_ptr clone() const;
	virtual ~TermConstant();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	std::string getValue();
	std::string getType();

	Primitive_ptr primitive;
};

/**
 *  : "(" identifier sort_list_ ")"
 *  | identifier
 *  | type
 */
class Sort : public Visitable {
public:
	Sort(Identifier_ptr);
	Sort(Identifier_ptr, SortList_ptr);
	Sort(VarType_ptr);
	Sort(const Sort&);
	virtual Sort_ptr clone() const;
	virtual ~Sort();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Identifier_ptr identifier;
	SortList_ptr sort_list;
	VarType_ptr var_type;

};

class VarType : public Visitable {
public:
	VarType(type_VAR type);
	VarType(const VarType&);
	virtual VarType_ptr clone() const;
	virtual ~VarType();

	virtual std::string str();
	virtual type_VAR getType();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	type_VAR type;
};

class TBool : public VarType {
public:
	TBool();
	TBool(const TBool&);
	virtual TBool_ptr clone() const;
	virtual ~TBool();

	virtual std::string str();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);
};

class TInt : public VarType {
public:
	TInt();
	TInt(const TInt&);
	virtual TInt_ptr clone() const;
	virtual ~TInt();

	virtual std::string str();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

};

class TString : public VarType {
public:
	TString();
	TString(const TString&);
	virtual TString_ptr clone() const;
	virtual ~TString();

	virtual std::string str();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);
};

/**
 * : KEYWORD attribute_value
 * | KEYWORD
 */
class Attribute : public Visitable {
public:
	Attribute();
	Attribute(const Attribute&);
	virtual Attribute_ptr clone() const;
	virtual ~Attribute();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

};

/**
 * "(" SYMBOL sort ")"
 */
class SortedVar : public Visitable {
public:
	SortedVar(Primitive_ptr, Sort_ptr);
	SortedVar(const SortedVar&);
	virtual SortedVar_ptr clone() const;
	virtual ~SortedVar();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Primitive_ptr symbol;
	Sort_ptr sort;


};

/**
 * "(" SYMBOL term ")"
 */
class VarBinding : public Visitable {
public:
	VarBinding(Primitive_ptr, Term_ptr);
	VarBinding(const VarBinding&);
	virtual VarBinding_ptr clone() const;
	virtual ~VarBinding();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Primitive_ptr symbol;
	Term_ptr term;
};

/**
 *  "(" "_" SYMBOL numeral_list_ ")"
 * | SYMBOL
 */
class Identifier : public Visitable {
public:
	Identifier(Primitive_ptr);
	Identifier(Primitive_ptr, Primitive_ptr, NumeralList_ptr);
	Identifier(const Identifier&);
	virtual Identifier_ptr clone() const;
	virtual ~Identifier();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	std::string getName();
	std::string getType();
	bool isSymbolic();

	Primitive_ptr underscore;
	Primitive_ptr symbol;
	NumeralList_ptr numeral_list;
};

class Variable : public Visitable {
public:
	Variable(Primitive_ptr);
	Variable(const Variable&);
	virtual Variable_ptr clone() const;
	virtual ~Variable();

	std::string getName();
	type_VAR getType();

	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);

	Primitive_ptr primitive;
	type_VAR type;
};

enum class type_Primitive {
	NONE = 0, BINARY, DECIMAL, HEXADECIMAL, KEYWORD,
	NUMERAL, STRING, SYMBOL
};
class Primitive : public Visitable {
public:
	Primitive(std::string data, const std::string type);
	Primitive(const Primitive&);
	virtual Primitive_ptr clone() const;
	virtual ~Primitive();
	virtual void accept(Visitor_ptr);
	virtual void visit_children(Visitor_ptr);
	std::string str() const;

	std::string getData();
	void setData(std::string data);
	std::string getType();
	void setType(std::string type);


	static const std::string BINARY;
	static const std::string DECIMAL;
	static const std::string HEXADECIMAL;
	static const std::string KEYWORD;
	static const std::string NUMERAL;
	static const std::string STRING;
	static const std::string SYMBOL;
	static const std::string REGEX;

private:
	std::string data;
	std::string type;
};


// helper functions
void debug_deallocation(std::string msg);


} /* namespace SMT */
} /* namespace Vlab */

#endif /* SMT_AST_H_ */
