from matplotlib import pyplot

def get_data_from_file(file_name):
    file_data = []
    try:
        file = open(file_name, "r+")
        for line in file:
            file_data.append(float(line))
        file.close()
        return file_data
    except IOError:
        print("Could not open "+file_name)
        return False
    
if __name__ == "__main__":
    X_in = get_data_from_file("X_in.txt")
    Y_in = get_data_from_file("Y_in.txt")
    
    X_out = get_data_from_file("X_out.txt")
    Y_out = get_data_from_file("Y_out.txt")

    X_test = get_data_from_file("X_test.txt")
    Y_test = get_data_from_file("Y_test.txt")

    pyplot.semilogy(X_in, Y_in, 'r.', label='pełne dane')
    pyplot.semilogy(X_out, Y_out, color='blue', label='funkcja interpolująca')
    pyplot.semilogy(X_test, Y_test, 'g.', label='dane do interpolacji')
    pyplot.legend()
    pyplot.ylabel('Wysokość')
    pyplot.xlabel('Odległość')
    pyplot.title('Przybliżenie interpolacją Lagrange\'a, ' + str(len(interpolation_data)) + ' punkty(ów)')
    pyplot.suptitle(file)
    pyplot.grid()
    pyplot.show()
