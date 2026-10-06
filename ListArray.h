
#include <ostream>
#include <stdexcept>
#include "List.h"
template <typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;
	public:
		ListArray(){
			arr=new T[MINSIZE];
			n=0;
			max=MINSIZE;
		}
		~ListArray() override{
			delete[] arr;
		}
		T operator[](int pos){
			if(pos>=n||pos<0){
				throw;
				std::out_of_range("Posicion no valida");
			}
			return arr[pos];
		}
		friend std::ostream&
		operator<<(std::ostream& out,
		ListArray<T> &list);
	private:
		void resize(int new_size){
			T* nuevoArray= new T[new_size];
			for(int i=0;i<n;i++){
				nuevoArray[i]=arr[i];
			}
			delete[] arr;
			arr=nuevoArray;
			max= new_size;
		}
};
