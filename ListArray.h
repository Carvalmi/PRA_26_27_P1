
#include <ostream>
#include <stdexcept>
#include "List.h"
template <typename T>
class ListArray;
template <typename T>
std::ostream& operator<<(std::ostream& out,ListArray<T>& llist);
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
				throw std::out_of_range("Posicion no valida");
			}
			return arr[pos];
		}
		friend std::ostream&
		operator<< <T>(std::ostream& out,ListArray<T> &list);
		void insert(int pos,T e) override{
                        if(pos<0||pos>=n){
                                throw std::out_of_range("Posicion no valida");
                        }
                        resize(max+1);
                        for(int i=n-1;i>pos;i--){
                                arr[i]=arr[i-1];
                        }
                        arr[pos]=e;
			n++;
                }
		void append(T e) override{
                        if(n==max){
				resize(max+1);
			}
			arr[n]=e;
			n++;
                }
                void prepend(T e) override{
                        resize(max+1);
                        for(int i=max-1;i>0;i--){
                                arr[i]=arr[i-1];
                        }
                        arr[0]=e;
			n++;
                }
                T remove(int pos) override{
			if(pos<0||pos>=n){
				throw std::out_of_range("Posicion invalida!");
			}
                        T dat=arr[pos];
                        for(int i=pos;i<n-1;i++){
                                arr[i]=arr[i+1];
                        }
                        n--;
                        return dat;
                }
                T get(int pos) override{
                        if(pos<0||pos>=n){
                                throw std::out_of_range("Posicion no valida");
                        }
                        T dat=arr[pos];
                        return dat;
                }
                int search(T e){
                        int i=0;
                        T prob=arr[i];
                        while(prob!=e && i>n){
                                i++;
				prob=arr[i];
			}
			if(prob==e){
                                return i;
                        }else{
                                return -1;
                                }
                        }
                bool empty() override{
                        if(n==0){
                                return true;
                        }else{
                                return false;
                        }
                }
                int size() override{
                        return n;
                }

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
template <typename T>
std::ostream& operator<<(std::ostream& out,ListArray<T>& llist){
	for(int i=0;i<llist.n;i++){
		out << llist.arr[i]<<"";
	}
	return out;
}

