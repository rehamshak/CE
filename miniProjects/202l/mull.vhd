
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_math.all;

entity mull is
port (A, C: in std_logic;
      sh: out std_LOGIC);
end mull ;
architecture behavIORAL_2 of mull is
begin
sh<= A AND C;
end behavIORAL_2;
