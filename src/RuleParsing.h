#ifndef _RULE_PARSING_H_
#define _RULE_PARSING_H_
#include <vector>
#include <list>
#include <string>

struct Region 
{
	int left, right;
	Region(int _a = 0, int _b = 0) : left(_a), right(_b) 
	{}
};

struct Parser
{
	std::vector<std::list<Region>> rules;
	void addRule(const std::string& ruleStr);
	void addRegin(int a, int b, int id)
	{
		rules[id].push_back(Region(a, b));
	}
	bool checkOverlap();
};

void Parser::addRule(const std::string& ruleStr)
{//a1 : 
	rules.resize(rules.size() + 1);

}
#endif/*_RULE_PARSING_H_*/