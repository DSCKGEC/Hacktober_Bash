#For numbers between 1 and 9 billion

nos = {'0':["",""],'1':["One","Ten"],'2':["Two","Twenty"],
       '3':["Three","Thirty"],'4':["Four","Forty"],
       '5':["Five","Fifty"],'6':["Six","Sixty"],
       '7':["Seven","Seventy"],'8':["Eight","Eighty"],
       '9':["Nine","Ninety"]}
tens = {'1':"Eleven",'2':"Twelve",'3':"Thirteen",
        '4':"Fourteen",'5':"Fifteen",'6':"Sixteen",
        '7':"Seventeen",'8':"Eighteen",'9':"Nineteen"}
places = ["Hundred","Thousand","Million","Billion"]
arr = []
name = ''
pos = -1
n = input()
for i in range(0,10-len(n)):
    pos+=1
    arr.append(0)
for item in n:
    arr.append(item)
if pos ==-1:
    name += nos[arr[0]][0]+' '+places[-1]+' '
pos+=1
while pos<len(arr):
    if pos==1 or pos==4 or pos==7:
        if arr[pos] != '0':
            name+=nos[arr[pos]][0]+" "+places[0]+' '
    elif pos==2 or pos==5 or pos==8:
        if arr[pos] != '1':
            name+=nos[arr[pos]][1]+' '
        else:
            name+=tens[arr[pos]]+' '
    elif pos==6:
        if arr[pos]!='0':
            name+=nos[arr[pos]][0]+" "+places[1]+' '
        elif arr[pos-1]!='0':
            name+=places[1]+' '
    elif pos==9:
        name+=nos[arr[pos]][0]#intentionally no spaces provided bcoz its the last pos
    elif pos==3:
        if arr[pos]!='0':
            name+=nos[arr[pos]][0]+' '+places[2]+' '       
        elif arr[pos-1]!='0':
            name+=places[2]+' '
    pos+=1     
print(' '.join(name.split()))#bcoz of empty string provided by our '0'
