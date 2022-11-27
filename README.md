# Unity ImGui DirectX 11 Hook

## Original DX11 BaseHook by rdbo
This project is a basehook for any unity game/program that uses DirectX 11. It hooks the function Present from the D3D11 SwapChain and the Window Proc, and then implements cimgui with Dear ImGui 1.89.1 using <a href="https://github.com/rdbo/libmem">rdbo's memory lib</a>.  
  
## How to use
First of all, you have to make sure you have the <a href="https://www.microsoft.com/en-us/download/details.aspx?id=6812">DirectX SDK</a> and <a href="https://visualstudio.microsoft.com/">Visual Studio</a> installed.  
Then, you just need to open the solution on VS and do the changes you want.  
