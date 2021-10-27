#include <iostream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

int main (int argc, char* argv[]) {

  if (argc < 8) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity> <nbthreads> <granularity>"<<std::endl;
    return -1;
  }
 int functionID = std::stoi (argv[i]);
  int a = atoi (argv[2]);
  int b = atoi  (argv[3]);
  int n = atoi  (argv[4]);
  int intensity =  atoi(argv[5]);
  int nbthreads =  atoi(argv[6]);
  int granularity = atoi (argv[7]);
  
  
  float ban = 1.0 * (b-a) / n;
  
  SeqLoop s1;
  float sum = 0;
  
  auto start = std::chrono::steady_clock::now();
  std::atomic<int> processPointer = 0;
  
  switch(functionID)
  {
    case 1 :
      s1.parfor<float>(0, nbthreads, 1, 
            [&](float& tls) -> void{ 
              tls = 0;
            },
             [&](int pass, float& tls) -> void{
               int localProcessPointer = processPointer;
               processPointer += granularity;
               
            while (localProcessPointer < n){
              int endLoop = localProcessPointer + granularity;
              
            for (int i = localProcessPointer; i < endLoop; i++)
            {
              float x = a + ((i + 0.5) * ban);
              //
              tls += f1(x, intensity);
              
            }
              localProcessPointer = processPonter;
              processPointer += granularity;
            }
         
         },
               [&](float tls) -> void{
                 sum = tls * ban;
               }
             );
      break;
      case 2:
      
       s1.parfor<float>(0, nbthreads, 1, 
            [&](float& tls) -> void{ 
              tls = 0;
            },
             [&](int pass, float& tls) -> void{
               int localProcessPointer = processPointer;
               processPointer += granularity;
               
            while (localProcessPointer < n){
              int endLoop = localProcessPointer + granularity;
              
            for (int i = localProcessPointer; i < endLoop; i++)
            {
              float x = a + ((i + 0.5) * ban);
              //
              tls += f2(x, intensity);
              
            }
              localProcessPointer = processPonter;
              processPointer += granularity;
            }
         
         },
               [&](float tls) -> void{
                 sum = tls * ban;
               }
             );
      break;
      case 3:
       s1.parfor<float>(0, nbthreads, 1, 
            [&](float& tls) -> void{ 
              tls = 0;
            },
             [&](int pass, float& tls) -> void{
               int localProcessPointer = processPointer;
               processPointer += granularity;
               
            while (localProcessPointer < n){
              int endLoop = localProcessPointer + granularity;
              
            for (int i = localProcessPointer; i < endLoop; i++)
            {
              float x = a + ((i + 0.5) * ban);
              //
              tls += f3(x, intensity);
              
            }
              localProcessPointer = processPonter;
              processPointer += granularity;
            }
         
         },
               [&](float tls) -> void{
                 sum = tls * ban;
               }
             );
      break;
      case 4:
       s1.parfor<float>(0, nbthreads, 1, 
            [&](float& tls) -> void{ 
              tls = 0;
            },
             [&](int pass, float& tls) -> void{
               int localProcessPointer = processPointer;
               processPointer += granularity;
               
            while (localProcessPointer < n){
              int endLoop = localProcessPointer + granularity;
              
            for (int i = localProcessPointer; i < endLoop; i++)
            {
              float x = a + ((i + 0.5) * ban);
              //
              tls += f4(x, intensity);
              
            }
              localProcessPointer = processPonter;
              processPointer += granularity;
            }
         
         },
               [&](float tls) -> void{
                 sum = tls * ban;
               }
             );
      break;
     default :
      std::cerr<<"invaid functionID";
      return -1;
  }
  auto end =std::chrono:: steady_clock::now();
  auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  float elapsed = milliseconds / 1000.0;
  
  std::cout << std::to_string(sum) << std::end1
  std::cerr << std::to_string(elapsed) << std::end1;
  
  return 0;
}
