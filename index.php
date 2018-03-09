<?php
include("common.inc");
startpage("Login");
if(isset($_GET['notset'])) {?>
<script>
    alert('You must input your MTurk number')
</script><?php
};?>
<body>
<div id="contentwrapper">
    <div id="loginbox">
        <form name="form2" method="post" action="beginauto.php">  
            <table>
                <tr>
                    <td> 
                        <div>
                            <b>Login</b> with Worker ID:
                        </div>
                    </td>
                    <td>
                        <input type="text" style="width: 100%;" name="loginpp" autocomplete="off">
                    </td>
                </tr>
                <tr>
                    <td> 
                        <div>
                        (must match for payment)
                        </div>
                    </td>
                    <td> 
                        <div>
                            <input type='hidden' name='scwidth' id="test1" value='1'>
                            <input type='hidden' name='scheight' id="test2" value='2'>
                            <input type="submit" style="width: 47.5%; margin-right:5%;" class="sexybutton" name="Proceed" value="Proceed">
                        </div>
                    </td>
                </tr>
            </table>
        </form>
    </div>
</div>
<script type="text/javascript">
    document.getElementById('test1').value = screen.width;
    document.getElementById('test2').value = screen.height;
</script>
</body>
</html>
