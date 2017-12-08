using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Example
{
    class Program
    {
        static void Main(string[] args)
        {
            //This is a bare bones example that shows the logic in which one might
            //Implement Spitfire into their application
            //TODO a full fledged example
            Console.WriteLine("Create WebRtcSession111");
            var test = new WebRtcSession("abc");
            Thread.Sleep(60000);
            Console.WriteLine(test.Id);
            Console.ReadLine();
        }
    }
}
