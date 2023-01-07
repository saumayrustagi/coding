defmodule Test do
	import IO
	def test do
		puts("Hello world from Elixir"<>" 4")
		puts(is_integer(4))
	end
end

Test.test
