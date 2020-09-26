from expense_service import ExpenseService
from user import User
class ExpenseManager(object):

    def __init__(self):
        self.all_balances = {}
        self.user_map = {}
    
    def add_user(self,user_id,name,email,mob_no):
        self.user_map[user_id] = User(user_id,name,email,mob_no)
    
    def get_user(self,user_id):
        return self.user_map[user_id]
        
    def add_expense(self,ExpenseType,amount,paid_by,splits):
    
        is_valid_expense,expense = ExpenseService().create_expense(ExpenseType,amount,paid_by,splits)
        if is_valid_expense == False:
            return
        if paid_by not in self.all_balances:
            self.all_balances[paid_by] = {}
        
        for split in expense.get_splits():
            user_owes = split.user
            if user_owes not in self.all_balances[paid_by]:
                self.all_balances[paid_by][user_owes] = 0.0
            self.all_balances[paid_by][user_owes] += split.amount

            if user_owes not in self.all_balances:
                self.all_balances[user_owes] = {}
            
            if paid_by not in self.all_balances[user_owes]:
                self.all_balances[user_owes][paid_by] = 0.0
            
            self.all_balances[user_owes][paid_by] -= split.amount

    def show_balance_of_user(self,user_id):
        user = self.get_user(user_id)
        if user not in self.all_balances:
            print("No balances")
        else:
            for assigned_user in self.all_balances[user]:
                self.show_balance(user,assigned_user)
    
    def show_balance(self, user, assigned_user):
        balance = self.all_balances[user][assigned_user]
        user_paid = ""
        user_owes = ""

        if balance == 0:
            return 
        
        if balance < 0:
            user_owes = user.get_name()
            user_paid = assigned_user.get_name()
        else:
            user_owes = assigned_user.get_name()
            user_paid = user.get_name()
        
        print("{} owes {}: {}".format(user_owes,user_paid,abs(balance)))
