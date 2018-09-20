require 'test_helper'

class WelControllerTest < ActionDispatch::IntegrationTest
  test "should get check" do
    get wel_check_url
    assert_response :success
  end

end
