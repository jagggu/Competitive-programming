
from equal_expense import EqualExpense
from exact_expense import ExactExpense
from percent_expense import PercentExpense

class ExpenseService(object):
    def __init__(self):
        pass
    
    def create_expense(self,ExpenseType,amount,paid_by,splits):        
        if ExpenseType == "EQUAL":
            return self.create_equal_expense(amount,paid_by,splits)
        elif ExpenseType == "EXACT":
            return self.create_exact_expense(amount,paid_by,splits)
        else:
            return self.create_percent_expense(amount,paid_by,splits)
    
    def create_equal_expense(self,amount,paid_by,splits):
        no_of_users = len(splits)
        equal_amount = round(amount/no_of_users,2)
        for split in splits:
            split.set_amount(equal_amount)  
        equal_expenses = EqualExpense(amount,paid_by,splits)
        return True,equal_expenses
    
    def create_exact_expense(self, amount, paid_by,splits):
        exact_expenses = ExactExpense(amount,paid_by,splits)
        is_valid_expense = exact_expenses.is_valid_expense()
        return is_valid_expense,exact_expenses
    
    def create_percent_expense(self,amount,paid_by,splits):
        for split in splits:
            split_amount = (amount/100) * split.percent
            split.set_amount(round(split_amount,2))
        percent_expenses = PercentExpense(amount,paid_by,splits)

        is_valid_expense = percent_expenses.is_valid_expense()
        return is_valid_expense,percent_expenses


        