using Vetche2D.Engine;
using IronPython.Hosting;

namespace Vetche2D.Scripting
{
    class PythonScriptLoader
    {
        public void Load(string filePath)
        {
            var engine = Python.CreateEngine();
            var scope = engine.CreateScope();
            engine.ExecuteFile(filePath, scope);
            dynamic mainClass = scope.GetVariable("VetcheMain");
            var main = mainClass();
        }
    }
}