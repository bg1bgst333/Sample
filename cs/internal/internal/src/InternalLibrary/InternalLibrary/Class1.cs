using System;
using System.Collections.Generic;
using System.Text;

namespace InternalLibrary
{
    public class Class1
    {
        public static int PublicMethod()
        {
            int ret = InternalClass.InternalMethod();
            return ret + 100;
        }
    }

    internal class InternalClass
    {
        internal static int InternalMethod()
        {
            return 100;
        }
    }
}
