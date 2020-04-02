"""
This is python file is for making game tic-tac-toe board.
"""

def demoBoard():
	'''
	This function is for giving input demo for better interface.
	'''
	print('''
		Instruction:
		Below given the sample board with keystock input combination.
		tl: top-left
		tm: top-middle
		tr: top-right
		ml: middle-left
		mm: middle-middle
		mm: middle-right
		ll: low-left
		lm: low-middle
		lr: low-right
		For example: input 'mm' to get 'X' on middle-middle of the board.
					 -+-+-
					 -+X+-
					 -+-+-
		''')
	print('                tl|tm|tr')
	print('                --+--+--')
	print('                ml|mm|mr')
	print('                --+--+--')
	print('                ll|lm|lr')
	print('\n')
	print('Thank You and Best of luck')
	print('\n')

def drawBoard(theBoard):
	'''
	This function is used for drawing the Board every time the function is called with objects of board elements.
	This give program better UI experiance.
	'''
	print('\t'+theBoard['TL']+'|'+theBoard['TM']+'|'+theBoard['TR'])
	print('\t-+-+-')
	print('\t'+theBoard['ML']+'|'+theBoard['MM']+'|'+theBoard['MR'])
	print('\t-+-+-')
	print('\t'+theBoard['LL']+'|'+theBoard['LM']+'|'+theBoard['LR'])

def checkInput(bInput,bBoard):
	'''
	This function is for checking the input is valid key cobmination and check if it can be placed inside the element or not.
	The function takes input keystocks and board objects and return true or false.
	'''
	bInput = bInput.upper()

	if bInput == 'TL' or  bInput == 'TM' or bInput == 'TR' or bInput == 'ML' or bInput == 'MM' or bInput == 'MR' or bInput == 'LL' or bInput == 'LM' or bInput == 'LR' :
		if bBoard[bInput] == ' ':
			return True
		else:
			return False
	else:
		return False

def checkWinner(theBoard,num):
	'''
	This function is for checking weather player has won or not.
	The function takes object board and number and return true or false.
	'''
	winnerP = [						#This array contain all winning posibility.
		['TL','TM','TR'],
		['ML','MM','MR'],
		['LL','LM','LR'],
		['TL','ML','LL'],
		['TM','MM','LM'],
		['TR','MR','LR'],
		['TL','MM','LR'],
		['LL','MM','TR']
	]

	if num%2 == 0:
		ch='O'
	else:
		ch='X'
	
	for winP in winnerP:
		if theBoard[winP[0]] == ch and theBoard[winP[1]] == ch and theBoard[winP[2]] == ch:
			return True
	return False

def main():
	'''
	This is main function all input and algorithm take palce.
	'''
	Board={'TL':' ','TM':' ','TR':' ',
		  'ML':' ','MM':' ','MR':' ',
		  'LL':' ','LM':' ','LR':' '}
	demoBoard()
	drawBoard(Board)

	for i in range(1,10):
		print('Turn number:', i)

		if i%2 == 0:
			print('_________________USER 2_______________')
		else:
			print('_________________USER 1_______________')

		boolen=False
		takeInput=str(input('Enter: '))
		while(boolen == False):
			
			boolen=checkInput(takeInput,Board)
			if boolen == True:
				if i%2 == 0:
					Board[takeInput.upper()]='O'
				else:
					Board[takeInput.upper()]='X'
			else:
				print('You have enter wrong input please correctly')
				takeInput=str(input('Enter: '))
		drawBoard(Board)
		# print(checkWinner(Board,i))
		if i >= 5:
			if checkWinner(Board,i) == True:
				print('_______WINNER_CHICKEN_DINNER________')
				return
		print('')
		print('_________________________________________')
		print('')
	print('________DRAW__________')
if __name__ == '__main__':
	main()