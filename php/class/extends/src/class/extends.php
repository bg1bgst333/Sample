<html>
  <head>
    <title>class#extends</title>
  </head>
  <body>
    <?php
      class BaseClass{
        private $basedata;
        public function setBaseData($in){
          $this->basedata = $in;
        }
        public function getBaseData(){
          return $this->basedata;
        }
      }
      class DerivedClass extends BaseClass{
        private $deriveddata;
        public function setDerivedData($in){
          $this->deriveddata = $in;
        }
        public function getDerivedData(){
          return $this->deriveddata;
        }
      }
      $b = new BaseClass();
      $b->setBaseData("Taro");
      echo $b->getBaseData();
      $d = new DerivedClass();
      $d->setBaseData("Jiro");
      $d->setDerivedData("Saburo");
      echo $d->getBaseData();
      echo $d->getDerivedData();
    ?>
  </body>
</html>
