#include <iostream>
#include <vector>
#include <string>
using namespace std;

int new_row() {		//creates new row and returns it
	int num_rows;
	cout << "Enter the number of rows in this matrix --> ";
	cin >> num_rows;
	cout << endl;
	return num_rows;
}

int new_column() {		//creates new column and returns it
	int num_cols;
	cout << "Enter the number of columns in this matrix --> ";
	cin >> num_cols;
	cout << endl;
	return num_cols;
}

vector<vector<int>> resize(int num_rows, int num_cols) {		//initializes matrix at a given size and returns it
	vector<vector<int>> return_matrix;
	return_matrix.resize(num_rows);

	for (int i = 0; i < return_matrix.size(); i++) {
		return_matrix.at(i).resize(num_cols);
	}
	return return_matrix;
}

vector<vector<int>> populate(int num_rows, int num_cols) {		//populates a given matrix from values from user and returns it
	vector<vector<int>> return_matrix;
	return_matrix = resize(num_rows, num_cols);

	cout << "Please enter the values in this matrix, you can enter " << num_rows << " rows and " << num_cols << " columns (seperated by spaces):" << endl;

	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_cols; j++) {
			cin >> return_matrix.at(i).at(j);
		}
	}
	return return_matrix;
}

vector<vector<int>> addVector(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {		//adds two vectors together and returns it
	vector<vector<int>> return_matrix;
	return_matrix = resize(matrix1.size(), matrix1.at(0).size());

	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1.at(0).size(); j++) {
			return_matrix.at(i).at(j) = matrix1.at(i).at(j) + matrix2.at(i).at(j);
		}
	}
	return return_matrix;
}

vector<vector<int>> multVector(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {		//multiplies two vectors together and returns it
	vector<vector<int>> return_matrix;
	return_matrix = resize(matrix1.size(), matrix2.at(0).size());

	for (int i = 0; i < matrix1.size(); ++i) {
		for (int j = 0; j < matrix2.at(0).size(); ++j) {
			for (int k = 0; k < matrix1.at(0).size(); ++k) {
				return_matrix.at(i).at(j) += matrix1.at(i).at(k) * matrix2.at(k).at(j);
			}
		}
	}
	return return_matrix;
}

void print(vector<vector<int>> matrix) {		//prints out a given matrix
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.at(0).size(); j++) {
			cout << matrix.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int>> matrix1;
	vector<vector<int>> matrix2;
	vector<vector<int>> final_matrix;
	char keep_going = 'h';

	do {
		matrix1 = resize(new_row(), new_column());						//initializes matrix1 and prints it
		matrix1 = populate(matrix1.size(), matrix1.at(0).size());
		cout << endl << "You entered the grid matrix 1 as:" << endl;
		print(matrix1);
		cout << endl;

		matrix2 = resize(new_row(), new_column());						//initializes  matrix2 and prints it
		matrix2 = populate(matrix2.size(), matrix2.at(0).size());
		cout << endl << "You entered the grid matrix 2 as:" << endl;
		print(matrix2);

		if (matrix1.size() == matrix2.size() && matrix1.at(0).size() == matrix2.at(0).size()) {		//adds matricies if you're able to add them together
			cout << endl << "Matrix 1 + Matrix 2 is:" << endl;
			final_matrix = addVector(matrix1, matrix2);
			print(final_matrix);
		}
		else {
			cout << endl << "Cannot add these matricies." << endl;
		}
		if (matrix1.at(0).size() == matrix2.size()) {			//multiplies matricies if you're able to multipy them together
			cout << endl << "Matrix 1 * Matrix 2 is:" << endl;
			final_matrix = multVector(matrix1, matrix2);
			print(final_matrix);
		}
		else {
			cout << endl << "Cannot multiply these matricies." << endl;
		}
		cout << endl << "Press Q to quit, any other key to do another grid --> ";
		cin >> keep_going;
		keep_going = toupper(keep_going);
		cout << endl;
	} while (keep_going != 'Q');
}