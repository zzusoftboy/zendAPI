// Copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by zzu_softboy on 27/07/2017.

#include "gtest/gtest.h"
#include "zapi/lang/Function.h"

using zapi::lang::Function;

void dummy_func(struct _zend_execute_data *executeData, struct _zval_struct *returnValue)
{}

TEST(FunctionTest, testConstructor)
{
   {
      Function func("zapi_version", dummy_func);
      zend_function_entry funcEntry;
      func.initialize(&funcEntry);
      ASSERT_STREQ(funcEntry.fname, "zapi_version");
      ASSERT_EQ(funcEntry.handler, &dummy_func);
      ASSERT_EQ(funcEntry.num_args, 0);
      ASSERT_EQ(funcEntry.flags, 0);
   }
}
