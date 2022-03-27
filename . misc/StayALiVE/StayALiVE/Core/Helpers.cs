using StayALiVE.Core.PBO;
using System;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace StayALiVE.Core
{
    internal class Helpers
    {
        internal static bool ApplicationRunning(string processName) => Process.GetProcessesByName(processName).Length > 1;

        internal static void ApplicationTerminate(string taskname)
        {
            string processName = taskname;
            string fixstring = taskname.Replace(".exe", "");

            if (taskname.Contains(".exe"))
            {
                foreach (Process process in Process.GetProcessesByName(fixstring))
                {
                    process.Kill();
                }
            }
            else if (!taskname.Contains(".exe"))
            {
                foreach (Process process in Process.GetProcessesByName(processName))
                {
                    process.Kill();
                }
            }
        }

        internal static void ApplicationTerminate(int taskID) => Process.GetProcessById(taskID).Kill();

        internal static void CopyFilesRecursively(string sourcePath, string targetPath)
        {
            foreach (string dirPath in Directory.GetDirectories(sourcePath, "*", SearchOption.AllDirectories)) Directory.CreateDirectory(dirPath.Replace(sourcePath, targetPath));
            foreach (string newPath in Directory.GetFiles(sourcePath, "*.*", SearchOption.AllDirectories)) File.Copy(newPath, newPath.Replace(sourcePath, targetPath), true);
        }
        
        internal static void PackPBO(string target)
        {  
            PboFile pbo = new();

            if (File.Exists($"{target}.pbo")) File.Delete($"{target}.pbo");

            foreach (string path in Directory.GetFiles(target, "*", SearchOption.AllDirectories))
            {
                string pathNew = path.Replace(target, "");
                string file = File.ReadAllText(path);
                byte[] fileBytes = Encoding.UTF8.GetBytes(file);
                string filePath = pathNew.StartsWith(@"\") ? pathNew.Substring(1) : pathNew;
                pbo.AddEntry(filePath, fileBytes);
            }

            pbo.Save($"{target}.pbo"); 
        } 
    }
}
