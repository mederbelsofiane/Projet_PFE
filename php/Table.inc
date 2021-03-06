<?php
class Table{
  public $table=array();
  public $head;
  public $GET;
  public function __construct($data){
    $this->table=$data["table"];
    $this->head=$data['head'];
  }
  public function head()
  {
    foreach ($this->head as $k => $v) {
      echo "<th>$v</th>";
    }
  }
  public function Table()
  {
    foreach ($this->table as $k => $v) {
      echo $v->AfficheRow();
    }
  }
  public function NumPage($GET)
  {
    if(isset($GET['page'])){
      $page=$GET['page'];
    }else{
     $page=1;
    }
    return $page;
  }
  public function printitem($id,$style,$get,$nom)
  {
     echo "<li class='$style'><a href='$nom?".$get."page=$id'>$id</a></li>";
  }
  public function FilterGET($GET)
  {
    $s="";
    foreach ($GET as $k => $v) {
        if($k!="page"){
           $s.=$k."=".$v."&";
        }
    }
    return $s;
  }
  public function bar($nom){
    echo '<div class="tableinfo" id="tableinfo"><ul class="listinfo">';
    $page=$this->NumPage($this->GET);
    if($page>1){
          $precedant=$page-1;
          echo "<li class='suivprec'><a href='$nom?".$this->GET."page=$precedant'><img src='img/precedant.png'/></a></li>";
          $this->printitem($precedant,"listitem",$this->GET,$nom);
          $this->printitem($_GET['page'],"itemactiv",$this->GET,$nom);
    }else{
        echo "<li class='suivprec'><a href='$nom?".$this->GET."page=1'><img src='img/precedant.png'/></a></li>";
        $this->printitem(1,"itemactiv",$this->GET,$nom);
    }
    $suivant=$page*10;
    /*
    $database=new database();
    $result=$database->query($this->sql." limit $suivant ,2");
    */
    if($page>1){$suivant=$page;}else{$suivant=1;}
    /*
    if(mysqli_num_rows($result)>0){
    $suivant++;
    $this->printitem($suivant,"listitem",$this->GET,$nom);
    }
    */
      echo "<li class='suivprec'><a href='$nom?".$this->GET."page=$suivant'><img src='img/suivant.png'/></a></li></ul></div>";
  }
}
