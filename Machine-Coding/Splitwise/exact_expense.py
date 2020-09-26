
from expense import Expense

class ExactExpense(Expense):

    def __init__(self,amount,paid_by,splits):
        Expense.__init__(self,amount,paid_by,splits)
        self.amount = amount
    
    def is_valid_expense(self):
        current_amount = 0

        for split in self.splits:
            current_amount += split.amount
            if current_amount > self.amount:
                return False
        
        return True
