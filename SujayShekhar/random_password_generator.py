import random
import string

def random_password_generator(size=4, chars=string.ascii_lowercase + string.digits):
    return ''.join(random.choice(chars) for _ in range(size))


print(random_password_generator())

print(random_password_generator(size=50))