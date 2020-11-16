def createSub lcs, x, y, i, j
     
     if i == 0 or j == 0  
       
    	return

     end	
    
    	if x[ i ].to_i == y[ j ].to_i
           
    	   createSub(lcs, x, y, i - 1, j - 1)

    	   print x[i], " " 	   

    	else

    		if lcs[ i ][ j - 1] < lcs[ i - 1 ][ j ]

    			createSub(lcs, x, y, i - 1, j)

    		else

                createSub(lcs, x, y, i, j - 1)

    	    end	

    	end	    
end

def max a,b

    if a > b
    	return a
    else
    	return b
    end 	
end	

def main    

	x = [0, 1, 7, 3, 5, 8]	
    y = [0, 7, 5, 8, 1]

    n = 5
    m = 4
    lcs = Array.new(n+1){Array.new(m+1,0)} 

    1.upto(n) { 

    	|i|
        
    	1.upto(m) {

    		|j|
            
            if x[i].to_i == y[j].to_i
                
                lcs[i][j] = 1 + lcs[i-1][j-1].to_i       
                                    
    		else

    			lcs[i][j] = max(lcs[i][j-1].to_i, lcs[i-1][j].to_i)
    	    end
    	}
        
    } 

    p lcs[n][m]
    
    createSub(lcs, x, y, n, m)
end   

main	
