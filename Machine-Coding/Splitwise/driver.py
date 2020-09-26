from expense_manager import ExpenseManager
from equal_split import EqualSplit
from exact_split import ExactSplit
from percent_split import PercentSplit

def main():

    expense_manager_obj = ExpenseManager()
    expense_manager_obj.add_user("u1","Jaggu","jagadeesh.vedas@gmail.com","9896812843")
    expense_manager_obj.add_user("u2","Sukku","sukumar@gmail.com","7093231707")
    expense_manager_obj.add_user("u3","Sudhakar","sudhakar@gmail.com","8885959277")
    expense_manager_obj.add_user("u4","Janaki","Janaki@gmail.com","9502836130")
    while(True):
        splits = []
        commands = input().split()
        if commands[0] == "EXIT":
            break
        
        if commands[0] == "SHOW":
            expense_manager_obj.show_balance_of_user(commands[1])
        if commands[0] == "EXPENSE":
            no_of_users = int(commands[3])
            ExpenseType = commands[3+no_of_users+1]
            amount = int(commands[2])
            paid_by = expense_manager_obj.get_user(commands[1])

            if ExpenseType == "EQUAL":
                for i in range(no_of_users):
                    user_id = commands[4+i]
                    splits.append(EqualSplit(expense_manager_obj.get_user(user_id))) 
                expense_manager_obj.add_expense("EQUAL",amount,paid_by,splits)
            elif ExpenseType == "EXACT":
                for i in range(no_of_users):
                    user_id = commands[4+i]
                    split_amount = int(commands[3+no_of_users+2+i])
                    splits.append(ExactSplit(expense_manager_obj.get_user(user_id),split_amount))
                
                expense_manager_obj.add_expense("EXACT",amount,paid_by,splits)
            elif ExpenseType == "PERCENT":
                for i in range(no_of_users):
                    user_id = commands[4+i]
                    split_percent = int(commands[3+no_of_users+2+i])
                    splits.append(PercentSplit(expense_manager_obj.get_user(user_id),split_percent))
                expense_manager_obj.add_expense("PERCENT",amount,paid_by,splits)


if __name__ == "__main__":
    main()