//
// Created by Pradyun Devarakonda on 11/03/25.
//

#ifndef DATABASE_H
#define DATABASE_H

#include "Schema_Element.h"
#include "../include/external_includes.h"
#include "Relation.h"
#include "View.h"
#include "Constraint.h"
#include "CAttribute.h"
//#include "../include/fsnamespace.h"
using namespace std;
// Database Class
// The Database is a composition of Schema_Element objects.
class Database{
    std::string name;
    std::map<string,Relation*> relations; //Use a map instead of vector to store schema elements
   	std::map<string,View*> views;
    std::map<string,Constraint*> constraints;
    std::map<string,ForeignKeyConstraint*> fkconstraints;
    std::map<string,UniqueKeyConstraint*> uks;
    std::map<string,PrimaryKeyConstraint*> pks;
    std::string xmlFilePath;
public:
    Database();
    Database(const std::string& xmlFilePath);
    string getName() const;
    std::map<string,Relation*> getRelations() const;
    std::map<string,View*> getViews() const;
    std::map<string,Constraint*> getConstraints() const;
    std::string getXmlFilePath() const;
    void setName(const std::string& name);
    void setRelations(const std::map<string,Relation*>& relations);
    void setViews(const std::map<string,View*>& views);
    void setConstraints(const std::map<string,Constraint*>& constraints);
    void setXmlFilePath(const std::string& xmlFilePath);
    bool addRelation(Relation* relation);
    bool addView(View* view);
    bool addConstraint(Constraint* constraint);
    bool removeRelation(const std::string& relationName);
    bool removeView(const std::string& viewName);
    bool removeConstraint(const std::string& constraintName);
    bool addForeignKeyConstraint(ForeignKeyConstraint* fkconstraint);
    bool addUniqueKeyConstraint(UniqueKeyConstraint* ukconstraint);
    bool addPrimaryKeyConstraint(PrimaryKeyConstraint* pkconstraint);
    std::map<string,ForeignKeyConstraint*> getForeignKeyConstraints() const;
    std::map<string,UniqueKeyConstraint*> getUniqueKeyConstraints() const;
    std::map<string,PrimaryKeyConstraint*> getPrimaryKeyConstraints() const;
    Relation* getRelation(const std::string& relationName);
    View* getView(const std::string& viewName);
    Constraint* getConstraint(const std::string& constraintName);
    bool create() const;
	std::map<std::string, ForeignKeyConstraint*> getForeignKeyConstraintsForRelation(const std::string& relationName);
    ~Database();//Drop the database
};


#endif //DATABASE_H
