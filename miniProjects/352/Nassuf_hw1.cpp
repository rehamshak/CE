#include <iostream.h>
#include <fstream.h>
#include<math.h>
void read();
void count();
void showData();
void encrypt();
void decrypt();
void main(){
		char option;
		do {
		cout<<"\noptions :"<<endl;
		cout<<"1)Enter r to read file\n";
		cout<<"2)Enter c to count number of lines and size of file\n";
		cout<<"3)Enter s to show data between tags file\n";
		cout<<"4)Enter e to encrypt the file\n";
		cout<<"5)Enter d to decrypt the file\n";
		cout<<"6)Enter q to quit\n";
		cin>>option;
		// call function based on the user choice
		if(option=='r')     {read();}
		else if(option=='c'){count();}
		else if(option=='e'){encrypt();}
		else if(option=='s'){showData();}
		else if(option=='d'){decrypt();}
		else if(option=='q'){cout<<endl;}
		else {cout<<"You entered a wrong option\n";}
		}while(option!='q');
}//end of main function

void read(){char c;
				char path[60];
				cout<<"enter the file Path:"<<endl;
				cin>>path;
				cout<<endl;
				ifstream file(path);
				if(file.fail()){cout<<"File not found\n";}
				// reading code
				else{
				while(!file.eof()){file.get(c);
										 cout<<c;
										}}//end while & else
				cout<<endl;
				file.close();
}// end read function

void count(){char c;
				 char path[60];
				 int file_size=0;
				 int num_of_line=0;
				 cout<<"enter the file Path:"<<endl;
				 cin>>path;
				 cout<<endl;
				 ifstream file(path);
				 if(file.fail()){cout<<"File not found\n";}
				 // counting code
				 else{
				 while(!file.eof()){file.get(c);
										  file_size+=sizeof(c);
										  if(c=='\n')  num_of_line++;
										  }//end while
				 file.close();
				 cout<<endl<<"file size is :"<<file_size<<endl;
				 cout<<"number of lines in file is :"<<num_of_line<<endl;
             }//end else
}// end function count

void showData(){char c;
					 char path[60];
					 cout<<"enter the file Path:"<<endl;
					 cin>>path;
					 cout<<endl;
					 ifstream file(path);
					 if(file.fail()){cout<<"File not found\n";}
					 // reading code
					 else{
					 while(!file.eof()){file.get(c);
											  if(c=='>'){
											  while(!file.eof() && c!='<'){
											  file.get(c);
											  if(c=='<')break;
											  else cout<<c;																}
					}//end 2nd while
					}}//end 1st while & else
					file.close();
}//end function showData

void encrypt(){int enc=0;
					char c;
					char path[60];
					char path1[60];
					cout<<"enter the file you want to encrypt Path:"<<endl;
					cin>>path;
					cout<<endl;
					cout<<"enter the encrypted file Path:"<<endl;
					cin>>path1;
					cout<<endl;
					ifstream file(path);
					ofstream ofile(path1);
					if(file.fail()||ofile.fail()){cout<<"File not found\n";}
					// encryption code
					else{
					while(!file.eof()){file.get(c);
											 ofile<<c;
											 if(c=='>'){while(!file.eof() && c!='<')
																  {file.get(c);
																	if(c=='<') ofile<<c;
																	else{if(c=='\n'){ofile<<c;}
																		  else{if(file.eof())
																				 goto end;
																				 c=(int)c+enc;
																		       enc++;
																				 ofile<<c;}
																		  }//end 2nd else
																	}//end 3rd while
															}//end 1st if

											  }}//end 1st while & else
					end:
					file.close();
					ofile.close();
}// end function encrypt

void decrypt(){int dec=0;
					char c;
					char path[60];
					cout<<"enter the encrypted file Path:"<<endl;
					cin>>path;
					cout<<endl;
					ifstream file(path);
					if(file.fail()){cout<<"File not found\n";}
					//decryption code
					else{
					while(!file.eof()){file.get(c);
											 cout<<c;
											 if(c=='>'){while(!file.eof() && c!='<')
																  {file.get(c);
																	if(c=='<') cout<<c;
																	else{if(c=='\n'){cout<<c;}
																		  else{if(file.eof())
																				 goto end;
																				 c=(int)c-dec;
																				 dec++;
																				 cout<<c;}
																		  }//end 2nd else
																	}//end 2nd while
															}//end 1st if

											  }}//end 1st while & else
               end:
					file.close();
}// end function decrypt
