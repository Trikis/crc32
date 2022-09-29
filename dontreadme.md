
<li> cmake -DMultiThreading=ON  - > for multithreading version</li>
<li>Lets suppose you have built you project in folder: build. Your compile files wiil be in -> build - Debug(i_hate_crc32 or i_hate_crc32_multethreading) . Tests executable file will be in build - tests - Debug -tests.exe. Any executable file(i_hate_crc32 or i_hate_crc32_multethreading or tests.exe) you need move to the root directory</li>


# About Regelar expressions
<pre>
# Supports:
# - {n} and {m,n} repetition, but not unbounded + or * repetition
# - ? optional elements
# - [] character ranges
# - () grouping
# - | alternation
</pre>