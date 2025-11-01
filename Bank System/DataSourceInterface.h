#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector> 
class DataSourceInterface

{

protected:
	virtual void  addClient(Client& obj) = 0;
	virtual void  addEmployee(Employee& obj) = 0;
	virtual void  addAdmin(Admin& obj) = 0;
 	virtual vector<Client>   getAllClients() = 0;

	virtual vector<Employee>   getAllEmployees() = 0;
	virtual vector<Admin>   getAllAdmins() = 0;
 };

