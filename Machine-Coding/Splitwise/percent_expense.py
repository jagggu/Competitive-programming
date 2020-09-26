
from expense import Expense

class PercentExpense(Expense):

    def __init__(self,amount,paid_by,splits):
        Expense.__init__(self,amount,paid_by,splits)
        
    
    def is_valid_expense(self):

        current_percent = 0

        for split in self.splits:
            current_percent += split.percent
            if current_percent > 100:
                return False
        
        return True