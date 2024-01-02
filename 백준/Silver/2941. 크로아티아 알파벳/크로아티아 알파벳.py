s=input()
croatia=['c=','c-','dz=','d-','lj','nj','s=','z=']

while True: 

    temp=s  
    for char in croatia:
        if char in temp:  
            ind=temp.index(char)
            c=len(char)         
            temp=temp[:ind]+'/'+temp[ind+c:] 
           
            break
    if temp!=s: 
        s=temp
    else:      
        break
        
print(len(s))