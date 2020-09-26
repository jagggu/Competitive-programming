
class User(object):

    def __init__(self,user_id,name,email,mob_no):
        self.__user_id = user_id
        self.__name = name
        self.__email = email
        self.__mobile_number = mob_no
        self.__balance = 0.0
    
    def get_user_id(self):
        return self.__user_id
    
    def set_user_id(self,user_id):
        self.__user_id = user_id
    
    def get_name(self):
        return self.__name
    
    def set_name(self,name):
        self.__name = name
    
    def get_email(self):
        return self.__email
    
    def set_email(self,email):
        self.__email = email
    
    def get_balance(self):
        return self.__balance
    
    def set_balance(self,balance):
        self.__balance = balance
