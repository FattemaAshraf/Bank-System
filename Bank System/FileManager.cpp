#include "FileManager.h"
#include "FilesHelper.h"

 void FileManager::addClient(Client& obj) {
    FilesHelper::saveClient(obj);

}

 void FileManager::addEmployee(Employee& obj) {
    FilesHelper::saveEmployee(obj);

}

 void FileManager::addAdmin(Admin& obj) {
    FilesHelper::saveAdmin(obj);

}

 vector<Client> FileManager::getAllClients() {
    return FilesHelper::getClients();
}

 vector<Employee> FileManager::getAllEmployees() {
    vector<Employee> employees = FilesHelper::getEmployees();
    return employees;
}

 vector<Admin> FileManager::getAllAdmins() {
    vector<Admin> admins = FilesHelper::getAdmins();
    return admins;
}

 void FileManager::removeAllClients() {
    FilesHelper::clearFile(CLIENTS_FILE, CLIENT_LAST_ID_FILE);
}

 void FileManager::removeAllEmployees() {
    FilesHelper::clearFile(EMPLOYEES_FILE, EMPLOYEE_LAST_ID_FILE);
}

 void FileManager::removeAllAdmins() {
    FilesHelper::clearFile(ADMINS_FILE, ADMIN_LAST_ID_FILE);
}