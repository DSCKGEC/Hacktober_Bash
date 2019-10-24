from random import randint


print(
    """
    Welcome! This a number guessing game where you will start with 7 lives in
    order to guess a number or numbers between 0-10.
    So use them smartly.
    Press q to quit.
    """
    )
k = input("Press any key to start  ").lower()
number = randint(0,10)
life = 7
points = 0
while 1:
    user_no = input('Your guess - ')
    if user_no =='q':
        print('Thank You for playing this game!')
        break
    if int(user_no) == number:
        points += 3
        life += 1
        print('Your Points = ' + str(points) ,'Lives left = ' + str(life),sep='\n')
        number = randint(0,20) 
    else:
        life -= 1
        print('Lives left = ' + str(life))
    if life == 0:
        break  
print("Your Score = " + str(points))
