import numpy

def EditDistance(s1, s2):
    """ Computes the edit distance of two strings
    (str, str) -> (int, 2D-array) """
    ln_s1 = len(s1)
    ln_s2 = len(s2)

    # Initializing the matrix
    Matrix = numpy.zeros((ln_s1+1 , ln_s2+1))
    for i in range(ln_s2+1):
        Matrix[0][i] = i

    for i in range(ln_s1+1):
        Matrix[i][0] = i

    # Filling the matrix
    for i in range(1, ln_s1+1):
        for j in range(1, ln_s2+1):
            insertion = Matrix[i][j-1]   + 1
            deletion  = Matrix[i-1][j]   + 1
            mismatch  = Matrix[i-1][j-1] + 1
            match     = Matrix[i-1][j-1]
            if s1[i-1] == s2[j-1]:
                Matrix[i][j] = min(insertion, deletion, match)
            if s1[i-1] != s2[j-1]:
                Matrix[i][j] = min(insertion, deletion, mismatch)
    
    return (int(Matrix[ln_s1][ln_s2]), Matrix)

if __name__ == '__main__':
    s1, s2 = input(), input()
    edit_distance, Matrix = EditDistance(s1, s2)

    print(edit_distance)