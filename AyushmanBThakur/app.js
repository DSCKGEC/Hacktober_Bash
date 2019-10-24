let dynamic_part = document.getElementById("dynamic");
let button = document.getElementById("button");

let sayHello = () => {
  dynamic_part.innerText =
    "This is how dynamically content can be changed! Click the button again to see the thing again!";
  button.innerText = "Click Me Again!";
  button.removeAttribute("onclick");
  button.setAttribute("onclick", "sayHello2()");
};

let sayHello2 = () => {
  dynamic_part.innerHTML = `Lorem ipsum dolor sit amet consectetur adipisicing elit. Ratione
  doloremque reprehenderit nobis cupiditate nemo minus quo! Sed hic <button class="link" onclick="show_more()">...show more</button>`;
  button.innerText = "Click Me";
  button.removeAttribute("onclick");
  button.setAttribute("onclick", "sayHello()");
};

let show_more = () => {
  dynamic_part.innerText = `Lorem ipsum dolor sit amet consectetur adipisicing elit. Ratione doloremque reprehenderit nobis cupiditate nemo minus quo! Sed hic pariatur earum accusamus consequuntur officiis at. Quidem hic incidunt expedita laudantium doloribus libero exercitationem at eos aliquid dolorum vitae itaque molestias repellendus inventore, adipisci odit voluptatem aperiam officia quasi fugit in veniam temporibus. A porro necessitatibus ipsa nemo quos mollitia amet? Labore nihil consequuntur quisquam at natus exercitationem voluptatibus. Delectus repudiandae minima unde, at explicabo saepe eaque excepturi vel dolore quis alias facere magnam recusandae tempora, placeat esse iusto accusantium tempore dolor earum ut maiores veritatis aut! Provident modi ipsum asperiores incidunt accusamus adipisci, doloremque minus necessitatibus laboriosam a placeat cumque dolores sunt, rerum, quis debitis doloribus animi atque fuga veniam nesciunt iste. Sit debitis laboriosam ad soluta voluptatibus, ab a quas recusandae deleniti illo amet architecto cum quis eaque et nemo laudantium ipsum? Quaerat rem eum dolore distinctio provident rerum, obcaecati eius porro, corrupti ex veritatis ut facilis odio fuga culpa exercitationem illo officia temporibus veniam. Nobis, vero assumenda magni dolores hic a? Perspiciatis animi suscipit doloribus aspernatur, qui nulla a assumenda laborum iusto quod, quos dolor quas cumque facere ratione veritatis reiciendis tempore omnis voluptates ad? Iusto voluptate vel enim?`;
};
