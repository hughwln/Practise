
while True:
	name=input('what is your name?(enter "q" quit)')
	if name=='q':
		break
	else:
		say_hi=name.title()+", have a nice day!"
		print(say_hi)
		filepath='/Users/huyi/Documents/code/log.txt'
		file_object = open(filepath, 'a')
		file_object.write(say_hi)
		file_object.write('\n')
		file_object.close()






numbers = list(range(1,10))
for number in numbers:
	if number == 1:
		print('1st')
	elif number == 2:
		print('2nd')
	elif number == 3:
		print('3rd')
	else:
		print(str(number)+'th')



sen="How old are you?"
age=input(sen)
while age!='#':	
	if int(age)>0 and int(age)<3:
		print("You are free.")
	elif int(age)>=3 and int(age)<12:
		print("You should pay 10.")
	elif int(age)>=12:
		print("You should pay 15.")
	else:
		break;
	age=input(sen)

